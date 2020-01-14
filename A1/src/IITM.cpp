#include "../include/IITM.h"
#include<cstdlib>
#include<algorithm>
#include<string>

#define maxnamelength 5
#define maxhostels 10

template <typename T>
bool sortCGPA(T a, T b){
	if(a.cgpa > b.cgpa){
		return true;
	}
	return false;
}

template <typename T>
bool sortHostel(T a, T b){
	if(a.Hostel > b.Hostel){
		return true;
	}
	return false;
}

template <typename T>
bool sortGuidename(T a, T b){
	if(a.facads.name > b.facads.name){
		return true;
	}
	return false;
}

template <typename T>
bool sortRollN(T a, T b){
	if(a.RollN > b.RollN){
		return true;
	}
	return false;
}

std::string randomName(int length) {
  char consonents[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','z'};
  char vowels[] = {'a','e','i','o','u','y'};

  std::string name = "";

  int random = std::rand() % 2;
  int count = 0;

  for(int i = 0; i < length; i++) {
    if(random < 2 && count < 2) {
      name = name + consonents[std::rand() % 19];
      count++;
    }
    else {
      name = name + vowels[std::rand() % 5];
      count = 0;
    }
    random = std::rand() % 2;
  }
  return name;
}

void IITM::init(int N,int M){
	int bts = std::rand()%N + 1;
	int dds = N - bts;
	int hosts = std::rand()%maxhostels + 1;

	//creating faculties
	std::string n;
	bool f;
	Faculty temp;
	// std::cout<<"Creating "<<M<<" Faculties"<<std::endl;
	for(int i=0;i<M;i++){
		n = randomName(maxnamelength);
		// f = std::rand()%2;
		temp.init(n,false);
		faculties.push_back(temp);
	}

	//making some faculties permanent
	int permfacs = std::rand()%M + 1;
	for(int i=0;i<permfacs;i++){
		if(i%2 == 0){
			faculties[i].perm = true;
		}
	}
	// std::cout<<"Creating "<<hosts<<" Hostels"<<std::endl;

	//creating hostels
	for(int i=0;i<hosts;i++){
		n = randomName(maxnamelength);
		hostels.push_back(n);
	}

	std::string r;
	float cgpa;
	int hno;
	int x;
	BTech stud;
	//creating Btech students
	// std::cout<<"Creating "<<bts<<" BTech Students"<<std::endl;
	for(int i=0;i<bts;i++){
		cgpa = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
		hno = std::rand()%bts;
		r = "B";
		r = r + char(i+1 + '0');
		x = std::rand()%M;
		while(!faculties[x].isperm()){ //check what if no faculty is perm
			x = std::rand()%M;
		}
		stud.init(r,hostels[hno],faculties[x],cgpa);
		btechs.push_back(stud);
	}

	// std::cout<<"Creating "<<dds<<" DD Students"<<std::endl;
	DualDegree student;
	for(int i=0;i<dds;i++){
		cgpa = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
		r = "D";
		r = r + char(i+1 + '0');
		hno = std::rand()%dds;
		x = std::rand()%M;
		while(!faculties[x].isperm()){ //check what if no faculty is perm
			x = std::rand()%M;
		}
		student.init(r,hostels[hno],faculties[x],cgpa);
		duals.push_back(student);
	}
}

void IITM::assignFacs(){
	//assigning BTPGuides to BTechs
	std::sort(btechs.begin(),btechs.end(),sortCGPA);
	for(auto x:btechs){
		for(auto y:faculties){
			if(y.isperm() && (y.btps < 2)){
				x.BTPGuide = y;
				y.btps++;
				y.totprojectees++;
				break;
			}
		}
	}
	//assigning TASups to Duals
	for(auto x:duals){
		for(auto y:faculties){
			if((y.dds < 5)){
				x.DDPGuide = y;
				y.dds++;
				y.totprojectees++;
			}
		}
	}

	//assigning DDPGuides to Duals
	std::sort(duals.begin(),duals.end(),sortHostel);
	for(auto x:duals){
		for(auto y:faculties){
			if(y.isperm() && (y.dds < 2)){
				x.DDPGuide = y;
				y.dds++;
				y.totprojectees++;
			}
		}
	}

	

}

float IITM::checkStudswithsameDDGuidesTASups(){
	int count = 0;
	for(auto x:duals){
		if(x.DDPGuide == x.TASupervisor){
			count++;
			// std::cout<<x.RollN<<std::endl;
		}
	}
	return (count/duals.size())*100;
}

//m == 1 for Roll no sorting
//m == 2 for guidename sorting
// m == 3 for hostel name sorting
// void IITM::printStuds(int m){
// 	if(m == 1){
// 		std::sort(btechs.begin(),btechs.end(),sortRollN);
// 		std::sort(duals.begin(),duals.end(),sortRollN);
// 	}
// 	if(m == 2){
// 		std::sort(btechs.begin(),btechs.end(),sortGuidename);
// 		std::sort(duals.begin(),duals.end(),sortGuidename);
// 	}
// 	if(m == 3){
// 		std::sort(btechs.begin(),btechs.end(),sortHostel);
// 		std::sort(duals.begin(),duals.end(),sortHostel);
// 	}

// 	for(auto x:btechs){
// 		std::cout<<x.RollN<<std::endl;
// 	}
// 	for(auto x:duals){
// 		std::cout<<x.RollN<<std::endl;
// 	}
// }

void IITM::printddstuds(std::string hostel, Faculty fac){
	for(auto x:duals){
		if(x.Hostel == hostel){
			if((x.DDPGuide == fac) || (x.TASupervisor == fac)){
				std::cout<<x.RollN<<std::endl;
			}
		}
	}
}

Faculty IITM::maxprojectees(){
	int max = INT_MIN;
	Faculty fac;
	for(auto x:faculties){
		if(max < x.totprojectees){
			max = x.totprojectees;
			fac = x;
		}
	}
	return fac;
}
void IITM::check(){
	for(auto x:btechs){
		std::cout<<x.RollN<<std::endl;
	}
	for(auto x:duals){
		std::cout<<x.RollN<<std::endl;
	}
	for(auto x:faculties){
		std::cout<<x.name<<std::endl;
	}
}
