#include"../include/Faculty.h"
#include"../include/BTech.h"

using namespace std;

void BTech::init(std::string r,std::string h,Faculty f,float cg){
	RollN = r;
	Hostel = h;
	facad = f;
	cgpa = cg;
}
std::string BTech::getHostel(){
	return Hostel;
}

Faculty BTech::getFacad(){
	return facad;
}

void BTech::changeHostel(std::string h){
	Hostel = h;
}

Faculty BTech::getBTPGuide(){
	return BTPGuide;
}

void BTech::setBTPGuide(Faculty f){
	BTPGuide = f;
}
