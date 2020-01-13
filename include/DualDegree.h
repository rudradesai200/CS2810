#include<string>
#include"Faculty.h"

#ifndef dualdegree
#define dualdegree
class DualDegree{
	std::string RollN;
	std::string Hostel;
	Faculty facad;
	Faculty DDPGuide;
	Faculty TASupervisor;
	float cgpa;

	void init(std::string r,std::string h,Faculty f,float cg);
	std::string getHostel();
	Faculty getFacad();
	void changeHostel(std::string h);
	Faculty getDDPGuide();
	void setDDPGuide(Faculty f);
	Faculty getTASupervisor();
	void setTASupervisor(Faculty f);
};
#endif