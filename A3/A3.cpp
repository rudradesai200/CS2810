#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define MAX_DEGREE 21

class Polynomial{
public:
	int si;
	vector<double> coeff;
	
	void initCoeffs(int x){
		coeff.resize(MAX_DEGREE);
		for(int i=0;i<MAX_DEGREE;i++){coeff[i] = 0;}

		double temp;
		int idx;
		for(int i=0;i<x;i++){
			cin>>idx>>temp;
			coeff[idx]=temp;
		}
	}

	double evaluate(double x){
		double sum = 0;
		double po = 1;
		for(int i=0;i<ceil(MAX_DEGREE/2);i++){
			cout<<"22"<<endl;
			sum += coeff[i] * po;
			po = po * x;
		}
		return sum;
	}
	Polynomial operator+(Polynomial p){
			Polynomial result;
			for(int i=0;i<MAX_DEGREE;i++){
				double a=coeff[i];
				double b = p.coeff[i];
				result.coeff.push_back(a+b);
			}
			return result;
	}
	Polynomial operator-(Polynomial p){
			Polynomial result;
			for(int i=0;i<MAX_DEGREE;i++){
				double a=coeff[i];
				double b = p.coeff[i];
				result.coeff.push_back(a-b);
			}
			return result;
	}
	Polynomial operator*(Polynomial p){
			Polynomial result;
			for(int i=0;i<MAX_DEGREE;i++){result.coeff.push_back(0);}

			for(int i=0;i<ceil(MAX_DEGREE/2);i++){
				double a=coeff[i];
				if(a != 0){
					for(int j=0;j<ceil(MAX_DEGREE/2);j++){
						double b=p.coeff[j];
						if(b != 0){
							result.coeff[i+j] += (a*b);
						}
					}
				}
			}
			return result;
	}
	char sign(double x){
		if(x < 0){return '-';}
		return '+';
	}
	void print(){
		int i=0;
		int x=0;
		while(x<1){
			double a = coeff[i];
			if(a != 0){
				cout<<(a)<<"x^"<<i<<' ';
				x++;
			}
			i++;
		}
		while((i<(MAX_DEGREE))){
			double a = coeff[i];
			if(a != 0){
				cout<<sign(a)<<' '<<abs(a)<<"x^"<<i<<' ';
			}
			i++;
		}
		cout<<endl;
	}
};

int main(){
	int op;cin>>op;
	while(op--){
		int x;
		Polynomial q,p,r;
		char ope; cin>>ope;
		switch(ope){
			case 'a':
			cin>>x;
			p.initCoeffs(x);
			cin>>x;
			q.initCoeffs(x);
			r=p+q;
			r.print();
			break;
			case 'm':
			cin>>x;
			p.initCoeffs(x);
			cin>>x;
			q.initCoeffs(x);
			r=p*q;
			r.print();
			break;
			case 's':
			cin>>x;
			p.initCoeffs(x);
			cin>>x;
			q.initCoeffs(x);
			r=p-q;
			r.print();
			break;
			case 'e':
			cin>>x;
			p.initCoeffs(x);
			double y;cin>>y;
			cout<<"11"<<endl;
			cout<<r.evaluate(y)<<endl;
			break;
		}
	}
}