#include<string>
#include"Faculty.h"

#ifndef btech
#define btech
class BTech{
public:
	std::string RollN;
	std::string Hostel;
	Faculty facad;
	Faculty BTPGuide;
	float cgpa;

	void init(std::string r,std::string h,Faculty f,float cg);
	std::string getHostel();
	Faculty getFacad();
	Faculty getBTPGuide();
	void changeHostel(std::string h);
	void setBTPGuide(Faculty f);
};
#endif