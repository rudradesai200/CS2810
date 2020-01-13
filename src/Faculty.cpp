#include"../include/Faculty.h"

using namespace std;

void Faculty::init(std::string n,bool p){
		name = n;
		p = perm;
	}

bool Faculty::isperm(){
		return perm;
	}