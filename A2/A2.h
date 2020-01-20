#include<string>
#include<vector>

using namespace std;

class Pen{
	int id;
	float width;
	string color;
	string style;

	Pen(int id,float w,string c,string s);
	int getId();
	float getWidth();
	string getColor();
	string getStyle();
	void print();
};

class Pencil{
	int id;
	float width;
	string hmark;
	string psize;

	Pencil(int id,float w,string h,string p);
	int getId();
	float getWidth();
	string getHmark();
	string getPsize();
	void print();
};

class Item{
	int id;
	float price;
	string manufacturer;
	string type;
	int stat; //to check what does this item contain?
	Pen pe;
	Pencil pn;

	Item(int id,float price,string manu,string type);
	~Item();
	int getId();
	float getPrice();
	string getManufacturer();
	string getType();
	void addPen(Pen p);
	void addPencil(Pencil p);
	void print();
	void printpen();
	void printpencil();
};

class Inventory{
	vector<Item *> items; //collection of items
	
	void del();
	void add(char a);
	void print(char a);
};