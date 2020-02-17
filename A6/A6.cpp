#include "A6.h"

using namespace std;

functors::functors(int x){
	r = x;
	mode = 1;
}
functors::functors(string x){
	n = x;
	mode = 2;
}
bool functors::operator() (Student X){
	if(mode == 1) return (X.getRoll() == r);
	else if(mode == 2) return (X.getName() == n);
}

bool functors::operator() (Student X, Student Y){
	if(mode == 1){
		if(X.getAvg() > Y.getAvg()) return 1;
		else if( X.getAvg() == Y.getAvg())
			if(X.getRoll() < Y.getRoll())
				return 1;
		return 0;
	} else{
		if(X.getRoll() < Y.getRoll()){
			return 1;
		}
		return 0;
	}
} 

void print(Student X){
	X.print();
}
void printavg(Student X){
	X.printavg();   
}

int main(){
	std::cout << std::fixed << std::showpoint;
	std::cout << std::setprecision(4);
	int N; cin>>N;
	vector<Student> v;
	string x;
	int a,b,c,d;

	while(N--){
		cin>>x>>a>>b>>c>>d;
		v.push_back(Student(x,a,b,c,d));
	}

	int T; cin>>T;
	if(T == 1){
		cin>>a;
		functors fun(a);
		auto y = find_if(v.begin(),v.end(),fun);
		if(y != std::end(v)){
			y->print();
		}
		else{
			cout<<"Invalid Entry"<<endl;
		}
	} else {
		if(T == 2){
			cin>>x;
			vector<Student> res;
			functors fun(x);
			for(auto stu : v){
				if(fun(stu)){
					res.push_back(stu);
				}
			}
			sort(res.begin(),res.end(),fun);
			if(res.size() != 0) for_each(res.begin(),res.end(),print);
			else{ cout<<"Invalid Entry"<<endl;}
		} else {
			functors fun(0);
			sort(v.begin(),v.end(),fun);
			for_each(v.begin(),v.end(),printavg);
		}
	}
}
