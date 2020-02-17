#include<bits/stdc++.h>

using namespace std;

class Student{
	private:
		string Name;
		int RollNo;
		int Phy,Math,Chem;

	public:
		// constructor
		Student(string x,int r,int p,int c,int m):Name(x),RollNo(r),Phy(p),Chem(c),Math(m){}

		//getters for different parameter
		string getName() const {return Name;}
		int getRoll() const {return RollNo;}
		double getAvg() const {return (Phy + Math + Chem)/(3.00) ;}

		//for printing
		void print() const {cout<<Name<<' '<<RollNo<<' '<<Phy<<' '<<Chem<<' '<<Math<<endl;}
		void printavg() const {cout<<Name<<' '<<RollNo<<' '<<Phy<<' '<<Chem<<' '<<Math<<' '<<getAvg()<<endl;}
};

class functors{

	private:
		// parameters to use overloaded functors
		int r;
		string n;
		int mode;

	public:

		functors(int x);                            //defined for 1st operation
		functors(string x);                         //overloaded for 2nd operation
		bool operator() (Student X);                //defined for 1st operation
		bool operator() (Student X, Student Y);     //overloaded for 2nd operation
};

void print(Student X);                              //supports printing
void printavg(Student X);                           //supports printing
