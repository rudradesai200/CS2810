#include<string>
#ifndef faculty
#define faculty
class Faculty{
public:
	std::string name;
	bool perm;
	int btps;
	int dds;
	int totprojectees;
	int tasup;

	//operators and functions
	bool operator==(Faculty& other);
	void init(std::string n,bool p);
	bool isperm();
};
#endif