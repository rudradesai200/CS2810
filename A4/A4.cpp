#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

#define mod 1000000007

using namespace std;

int power(int x, unsigned long int y, unsigned long int m) 
{ 
    if (y == 0) 
        return 1; 
    long int p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
} 

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
    unsigned long int p;

    /* Constructor */
    Natural(unsigned long int a);

    /* other functions */
    bool isPrime();
    unsigned long int InvModP();

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
    cout<<(num.xx/den.xx) + (a.num.xx/a.den.xx)<<endl;
    return Rational((num * a.den + den * a.num).xx,(den * a.den).xx);
}
Rational Rational::operator-(Rational a){
    cout<<(num.xx/den.xx) - (a.num.xx/a.den.xx)<<endl; 
    return Rational((num * a.den - den * a.num).xx,(den * a.den).xx);
    
}
Rational Rational::operator*(Rational a){
    cout<<(num.xx/den.xx) * (a.num.xx/a.den.xx)<<endl;
    return Rational((num.xx / den.xx),(den * a.den).xx);
}

void Rational::Reduce(){
 long int p = num.xx;
 long int q = den.xx;
 long int a = __gcd(p,q);
    if(a!=1){
        p = p/a;
        q = q/a;
    }
    if((p < 0) || (q<0)){
        cout<<'-'<<abs(p)<<' '<<abs(q)<<endl;    
    }
    else
    cout<<p<<' '<<q<<endl;
}

void Rational::print(){
    cout<<((num.xx)/(den.xx))<<endl;
}

Natural::Natural(unsigned long int a):p(a){}

bool Natural::isPrime(){
    unsigned long int N = p;
    if(N<2 || (!(N&1) && N!=2))
        return 0;
    for(unsigned long int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return 0;
    }
    return 1;
}
unsigned long int Natural::InvModP(){
    unsigned long int a=p;
    unsigned long int m = mod;
    unsigned long int g = __gcd(a, m); 
    if (g != 1) {
        cout << "Inverse doesn't exist"; 
        return 0;
    }
    else
    { 
        return power(a, m-2, m); 
    }   
}

int main(){
    cout << setprecision(3)<<fixed;
 long int N;cin >>N;
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
                 long int a,b,c,d;
                    cin>>a>>b>>c>>d;
                    Rational A(a,b), B(c,d);
                    Rational C = A+B;
                    // C.print();
                }
                if(op == "sub"){
                 long int a,b,c,d;
                    cin>>a>>b>>c>>d;
                    Rational A(a,b), B(c,d);
                    Rational C = A-B;
                    // C.print();
                }
                if(op == "mult"){
                 long int a,b,c,d;
                    cin>>a>>b>>c>>d;
                    Rational A(a,b), B(c,d);
                    Rational C = A*B;
                    // C.print();
                }
                if(op == "reduce"){
                 long int a,b;
                    cin>>a>>b;
                    Rational A(a,b);
                    A.Reduce();
                }
            } else {
                if(t == "natural"){
                    string op; cin>>op;
                    if(op == "isprime"){
                        unsigned long int a;cin>>a;
                        Natural A(a);
                        cout<<A.isPrime()<<endl;
                    }
                    if(op == "inverse"){
                        unsigned long int a;cin>>a;
                        Natural A(a);
                        cout<<A.InvModP()<<endl;
                    }
                }
            }
        }
    }
}