#include<bits/stdc++.h>

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