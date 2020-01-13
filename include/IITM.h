#include<bits/stdc++.h>
#include"BTech.h"
#include"DualDegree.h"
#include"Faculty.h"

#ifndef iitm
#define iitm
class IITM{
	std::vector<BTech> btechs;
	std::vector<DualDegree> duals;
	std::vector<Faculty> faculties;
	std::vector<string> hostels;

	void init(int N,int M);
	// void assignFacads();
	void check();

};
#endif