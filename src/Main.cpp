#include "../include/IITM.h"
#include<iostream>

using namespace std;

int main(){
	IITM iitm;
	iitm.init(10,10);
	// iitm.check();
	std::cout<<iitm.checkStudswithsameDDGuidesTASups()<<endl;

	return 0;
}

