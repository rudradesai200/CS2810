#include<iostream>
#include<bits/stdc++.h>
#include"A2.h"

using namespace std;

bool sortitem(Item a, Item b){
	return (a.getid > b.getid);
}

//Pen class functions
Pen::Pen(int id,float w,string c,string s){
	id = id;
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
Pencil::Pencil(int id,float w,string c,string s){
	id = id;
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
Item::Item(int id,float price,string manu,string type){
	id = id;
	price= price;
	manufacturer = manu;
	type = type;
	stat = 0;
}
Item::~Item(){
	if(stat == 1){
		delete pe;
	}
	else if(stat == 2){
		delete pn;
	}
	delete this;
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
void Item::addPen(Pen p){
	stat = 1;
	pe = p;
}
void Item::addPencil(Pencil p){
	stat = 2;
	pn = p;
}
void Item::print(){
	cout<<id<<' '<<price<<' '<<manufacturer<<' '<<type<<endl;
}
void Item::printpen(){
	if(stat == 1){
		pe.print();
	}
}
void Item::printpencil(){
	if(stat == 2){
		pn.print();
	}
}

//Inventory class functions
void Inventory::del(){
	int t;
	cin >>t;
	for(auto x:items){
		if(x->getId == t){
			items.erase(x);
			delete x;
		}
	}
}
void Inventory::add(char a){
	if(a == 'a'){
		int i;
		float p;
		string m,t;
		cin>>i>>p>>m>>t;
		Item* temp = new Item(i,p,m,t);
		items.push_back(temp); 
	}
	else if(a == 'b'){
		int i;
		float p;
		string m,t;
		cin>>i>>p>>m>>t;
		Pen temp = new Pen(i,p,m,t);
		for(auto x:items){
			if(x->getId == i){
				x->addPen(temp);
			}
		} 
	}
	else if(a == 'c'){
		int i;
		float p;
		string m,t;
		cin>>i>>p>>m>>t;
		Pencil temp = new Pencil(i,p,m,t);
		for(auto x:items){
			if(x->getId == i){
				x->addPencil(temp);
			}
		} 
	}
}
void Inventory::print(char a){
	if(a == 'p'){
		sort(items.begin(),items.end(),sortitem);
		for(auto x:items){
			x.print();
		}
	}
	else if(a == 'q'){
		sort(items.begin(),items.end(),sortitem);
		for(auto x:items){
			x.printpen();
		}
	}
	else if(a == 'r'){
		sort(items.begin(),items.end(),sortitem);
		for(auto x:items){
			x.printpencil();
		}
	}
}

int main(){
	Inventory inv;
	int t;cin>>t;
	char t;
	while(t--){
		cin>>t;
		switch(t){
			case 'a':
			inv.add(t);
			break;
			case 'b':
			inv.add(t);
			break;
			case 'c':
			inv.add(t);
			break;
			case 'd':
			inv.del();
			break;
			case 'p':
			inv.print(t);
			break;
			case 'q':
			inv.print(t);
			break;
			case 'r':
			inv.print(t);
			break;
		}
	}
}