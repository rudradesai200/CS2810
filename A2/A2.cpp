#include<iostream>
#include<bits/stdc++.h>

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

public:
	Item(int id,float price,string manu,string type);
	int getId();
	float getPrice();
	string getManufacturer();
	string getType();
	void print();
};

class Inventory{
private:
	vector<Item *> items; //collection of items
	vector<Pen *> pens;
	vector<Pencil *> pencils;

public:	
	void del();
	void add(char a);
	void print(char a);
};

bool sortitem(Item* a, Item* b){
	int x = (a->getId());
	int y = b->getId();
	return (x<y);
}
bool sortpen(Pen* a, Pen* b){
	int x = (a->getId());
	int y = b->getId();
	return (x<y);
}
bool sortpencil(Pencil* a, Pencil* b){
	int x = (a->getId());
	int y = b->getId();
	return (x<y);
}
//Pen class functions
Pen::Pen(int ii,float w,string c,string s){
	id = ii;
	width = w;
	color = c;
	style = s;
}
int Pen::getId(){
	return id;
}
float Pen::getWidth(){
	return width;
}
string Pen::getColor(){
	return color;
}
string Pen::getStyle(){
	return style;
}
void Pen::print(){
	cout<<id<<' '<<width<<' '<<color<<' '<<style<<endl;
}

//Pencil class functions
Pencil::Pencil(int ii,float w,string c,string s){
	id = ii;
	width = w;
	hmark = c;
	psize = s;
}
int Pencil::getId(){
	return id;
}
float Pencil::getWidth(){
	return width;
}
string Pencil::getHmark(){
	return hmark;
}
string Pencil::getPsize(){
	return psize;
}
void Pencil::print(){
	cout<<id<<' '<<width<<' '<<hmark<<' '<<psize<<endl;
}

//Item class functions
Item::Item(int i,float pri,string manu,string ty){
	id = i;
	price= pri;
	manufacturer = manu;
	type = ty;
	stat = 0;
}
int Item::getId(){
	return id;
}
float Item::getPrice(){
	return price;
}
string Item::getManufacturer(){
	return manufacturer;
}
string Item::getType(){
	return type;
}
void Item::print(){
	cout<<id<<' '<<price<<' '<<manufacturer<<' '<<type<<endl;
}

//Inventory class functions
void Inventory::del(){
	int t;
	cin >>t;
	for(vector<Item *>::iterator x=items.begin();x!=items.end();x++){
		if((*x)->getId() == t){
			delete *x;
			items.erase(x);
			break;
		}
	}
	for(vector<Pen *>::iterator x=pens.begin();x!=pens.end();x++){
		if((*x)->getId() == t){
			delete *x;
			pens.erase(x);
			break;
		}
	}
	for(vector<Pencil *>::iterator x=pencils.begin();x!=pencils.end();x++){
		if((*x)->getId() == t){
			delete *x;
			pencils.erase(x);
			break;
		}
	}
	// cout<<items.size()<<endl;
}
void Inventory::add(char a){
	if(a == 'a'){
		int io;
		float p;
		string m,t;
		cin>>io>>p>>m>>t;
		Item* temp = new Item(io,p,m,t);
		items.push_back(temp); 
	}
	else if(a == 'b'){
		int ii;
		float p;
		string m,t;
		cin>>ii>>p>>m>>t;
		Pen* temp = new Pen(ii,p,m,t);
		pens.push_back(temp);
	}
	else if(a == 'c'){
		int ii;
		float p;
		string m,t;
		cin>>ii>>p>>m>>t;
		Pencil* temp = new Pencil(ii,p,m,t);
		pencils.push_back(temp);
	}
}
void Inventory::print(char a){
	if(a == 'p'){
		sort(items.begin(),items.end(),sortitem);
		for(auto x:items){
			x->print();
		}
	}
	else if(a == 'q'){
		sort(pens.begin(),pens.end(),sortpen);
		for(auto x:pens){
			x->print();
		}
	}
	else if(a == 'r'){
		sort(pencils.begin(),pencils.end(),sortpencil);
		for(auto x:pencils){
			x->print();
		}
	}
}

int main(){
	Inventory inv;
	int te;cin>>te;
	char t;
	while(te--){
		cin>>t;
		switch(t){
			case 'a': inv.add(t);
				break;
			case 'b': inv.add(t);
				break;
			case 'c': inv.add(t);
				break;
			case 'd': inv.del();
				break;
			case 'p': inv.print(t);
				break;
			case 'q': inv.print(t);
				break;
			case 'r': inv.print(t);
				break;
			default: cout<<"error"<<endl;
				break;
		}
	}
}