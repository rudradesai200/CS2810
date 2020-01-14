#include"../include/Faculty.h"
#include"../include/DualDegree.h"

void DualDegree::init(std::string r,std::string h,Faculty f,float cg){
	RollN = r;
	Hostel = h;
	facad = f;
	cgpa = cg;
}
std::string DualDegree::getHostel(){
	return Hostel;
}

Faculty DualDegree::getFacad(){
	return facad;
}

void DualDegree::changeHostel(std::string h){
	Hostel = h;
}

Faculty DualDegree::getDDPGuide(){
	return DDPGuide;
}

void DualDegree::setDDPGuide(Faculty f){
	DDPGuide = f;
}

Faculty DualDegree::getTASupervisor(){
	return TASupervisor;
}

void DualDegree::setTASupervisor(Faculty f){
	TASupervisor = f;
}