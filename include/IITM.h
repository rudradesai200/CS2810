#include<bits/stdc++.h>
 #include"BTech.h"
 #include"DualDegree.h"
 #include"Faculty.h"


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
	void check();

};
#endif
