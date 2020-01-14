#include"../include/Faculty.h"

using namespace std;

bool Faculty::operator==(Faculty& other){
	if(name != other.name){
		return false;
	}
	if(perm != other.perm){
		return false;
	}
	if(btps != other.btps){
		return false;
	}
	if(dds != other.dds){
		return false;
	}
	if(tasup != other.tasup){
		return false;
	}
	return true;
}
void Faculty::init(std::string n,bool p){
		name = n;
		p = perm;
		dds = 0;
		btps = 0;
		tasup = 0;
		totprojectees = 0;
	}

bool Faculty::isperm(){
		return perm;
	}

