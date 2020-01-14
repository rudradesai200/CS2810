#include<bits/stdc++.h>
 #include"BTech.h"
 #include"DualDegree.h"
 #include"Faculty.h"
#include<string>

#ifndef iit
#define iit
class IITM{
public:
	std::vector<BTech> btechs;
	std::vector<DualDegree> duals;
	std::vector<Faculty> faculties;
	std::vector<std::string> hostels;

	void init(int N,int M);
	void assignFacads();
	void assignFacs();
	float checkStudswithsameDDGuidesTASups();
	void printStuds(int m);
	void printddstuds(std::string hostel,Faculty fac);
	Faculty maxprojectees();
	void check();

};
#endif
