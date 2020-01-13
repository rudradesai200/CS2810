#include<string>
#ifndef faculty
#define faculty
class Faculty{
public:
	std::string name;
	bool perm;

	void init(std::string n,bool p);
	bool isperm();
};
#endif