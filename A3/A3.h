#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define MAX_DEGREE 11

class Polynomial{
public:
	int si;
	vector<double> coeff;
	
	void initCoeffs(int x); 			//to initialize coeffecients
	Polynomial operator+(Polynomial p); //operator overloading +
	Polynomial operator-(Polynomial p);	//operator overloading -
	Polynomial operator*(Polynomial p); //operator overloading *
	double evaluate(double x)			//evaluate function 
	char sign(double x);				//sign type return
	void print();						//printing Polynomial

};