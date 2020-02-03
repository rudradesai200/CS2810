#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;


class Complex
{
	public:
		/* fields */
		double xx;
		double yy;

		/* Constructor */
		Complex(double a,double b = 0);

		/* Overloaded Functions for add, sub and multiply */
		Complex operator+(Complex a);
		Complex operator-(Complex a);
		Complex operator*(Complex a);

		/* For debugging */
		void print();
};

class Rational:public Complex
{
public:
	/* fields */
	Complex num;
	Complex den;

	/* Constructor */
	Rational(int a,int b);

	/* Overloaded functions for add, sub, mult */
	Rational operator+(Rational a);
	Rational operator-(Rational a);
	Rational operator*(Rational a);

	/* other functions */
	void Reduce();
	void print();
};

class Natural
{
public:
	/* fields */
	int p;

	/* Constructor */
	Natural(int a);

	/* other functions */
	bool isPrime();
	int InvModP();

	/* for debugging */
	void print();
};

Complex::Complex(double a,double b):xx(a),yy(b){}
Complex Complex::operator+(Complex a){
	return Complex(xx + a.xx, yy + a.yy);
}
Complex Complex::operator-(Complex a){
	return Complex(xx - a.xx, yy - a.yy);
}
Complex Complex::operator*(Complex a){
	return Complex(xx * a.xx - (yy * a.yy),(yy * a.xx) + (xx * a.yy));
}

void Complex::print(){cout<<xx<<" "<<yy<<endl;}

Rational::Rational(int a,int b):num(a,0),den(b,0),Complex(0,0){}
Rational Rational::operator+(Rational a){
	return Rational((num * a.den + den * a.num).xx,(den * a.den).xx);
}
Rational Rational::operator-(Rational a){
	return Rational((num * a.den - den * a.num).xx,(den * a.den).xx);
}
Rational Rational::operator*(Rational a){
	return Rational((num * a.num).xx,(den * a.den).xx);
}
void Rational::Reduce(){
	int p = num.xx;
	int q = den.xx;
	int a = __gcd(p,q);
	if(a!=1){
		p = p/a;
		q = q/a;
	}
	cout<<p<<' '<<q<<endl;
}

void Rational::print(){
	cout<<((num.xx)/(den.xx))<<endl;
}

Natural::Natural(int a):p(a){}

bool Natural::isPrime(){
	int N = p;
	if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}
int Natural::InvModP(){
	int a = p;
	int m= 1000000007;
	int x = 0,y = 1,u = 1,v = 0; 
    int e = m,f = a;
    int c,d,q,r;
    while(f != 1)
    {
        q = e/f;
        r = e%f;
        c = x-q*u;
        d = y-q*v;
        x = u;
        y = v;
        u = c;
        v = d;
        e = f;
        f = r;
    } 
    u = (u+m)%m;
    return u;
}
int main(){
	cout << fixed;
	cout << setprecision(3);
	int N;cin >>N;
	while(N--){
		string t; cin>>t;
		if(t == "complex"){
			string op; cin>>op;
			if(op == "add"){
				double a,b,c,d;
				cin>>a>>b>>c>>d;
				Complex A(a,b), B(c,d);
				Complex C = A+B;
				C.print();
			}
			if(op == "sub"){
				double a,b,c,d;
				cin>>a>>b>>c>>d;
				Complex A(a,b), B(c,d);
				Complex C = A-B;
				C.print();
			}
			if(op == "mult"){
				double a,b,c,d;
				cin>>a>>b>>c>>d;
				Complex A(a,b), B(c,d);
				Complex C = A*B;
				C.print();
			}
		} else {
			if(t == "rational"){
				string op; cin>>op;
				if(op == "add"){
					int a,b,c,d;
					cin>>a>>b>>c>>d;
					Rational A(a,b), B(c,d);
					Rational C = A+B;
					C.print();
				}
				if(op == "sub"){
					int a,b,c,d;
					cin>>a>>b>>c>>d;
					Rational A(a,b), B(c,d);
					Rational C = A-B;
					C.print();
				}
				if(op == "mult"){
					int a,b,c,d;
					cin>>a>>b>>c>>d;
					Rational A(a,b), B(c,d);
					Rational C = A*B;
					C.print();
				}
				if(op == "reduce"){
					int a,b;
					cin>>a>>b;
					Rational A(a,b);
					A.Reduce();
				}
			} else {
				if(t == "natural"){
					string op; cin>>op;
					if(op == "isprime"){
						int a;cin>>a;
						Natural A(a);
						cout<<A.isPrime()<<endl;
					}
					if(op == "inverse"){
						int a;cin>>a;
						Natural A(a);
						cout<<A.InvModP()<<endl;
					}
				}
			}
		}
	}
}