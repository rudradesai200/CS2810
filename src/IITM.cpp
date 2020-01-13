#include "../include/IITM.h"
#include<cstdlib>

#define maxnamelength 5
#define maxhostels 10

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
	for(int i=0;i<M;i++){
		n = randomName(maxnamelength);
		f = std::rand()%2;
		temp.init(n,f);
		faculties.push_back(temp);
	}

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
	for(int i=0;i<bts;i++){
		cgpa = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
		hno = std::rand()%bts;
		r = 'B' + (i+1);
		x = std::rand()%M;
		while(!faculties[x].isperm()){ //check what if no faculty is perm
			x = std::rand()%M;
		}
		stud.init(r,hostels[hno],faculties[x],cgpa);
		btechs.push_back(stud);
	}

	DualDegree student;
	for(int i=0;i<dds;i++){
		cgpa = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
		r = 'D' + (i+1);
		hno = std::rand()%dds;
		x = std::rand()%M;
		while(!faculties[x].isperm()){ //check what if no faculty is perm
			x = std::rand()%M;
		}
		student.init(r,hostels[hno],faculties[x],cgpa);
		duals.push_back(student);
	}
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
