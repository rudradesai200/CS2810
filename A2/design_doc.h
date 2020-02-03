#include<string>
#include<vector>

using namespace std;

class Pen{
private:
	int id;
	float width;
	string color;
	string style;
public:
	Pen(int id,float w,string c,string s);
	int getId();
	float getWidth();
	string getColor();
	string getStyle();
	void print();
};

class Pencil{
private:
	int id;
	float width;
	string hmark;
	string psize;
public:
	Pencil(int id,float w,string h,string p);
	int getId();
	float getWidth();
	string getHmark();
	string getPsize();
	void print();
};

class Item{
private:
	int id;
	float price;
	string manufacturer;
	string type;
	int stat; //to check what does this item contain?
	Pen* pe;
	Pencil* pn;

public:
	Item(int id,float price,string manu,string type);
	~Item();
	int getId();
	float getPrice();
	string getManufacturer();
	string getType();
	void addPen(Pen *p);
	void addPencil(Pencil *p);
	void print();
	void printpen();
	void printpencil();
};

class Inventory{
private:
	vector<Item *> items; //collection of items
public:	
	void del();
	void add(char a);
	void print(char a);
};