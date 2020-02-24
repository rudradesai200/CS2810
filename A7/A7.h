#include<bits/stdc++.h>

using namespace std;

class Student{
    private:
    int ID;
    int marks[5];
    int skill;

    public:
    Student *left, *right;
    Student(int id,int a,int b,int c,int d, int e, int sk){
        ID = id;
        marks[0] = a;
        marks[0] = b;
        marks[0] = c;
        marks[0] = d;
        marks[0] = e;
        skill = sk;
        left = right = nullptr;

    }
    int getId(){return ID;}
    int getMarks(int i){
        return (marks[i]);
    }
    bool operator< (Student A){
        for(int i=0;i<5;i++)
            if(marks[i] > A.getMarks(i)){
                return 1;
            }
        
        return 0;
    }
    bool operator> (Student A){
        return !(*this < A);
    }
    void print(){
        cout<<ID<<' '<<marks[0]<<' '<<marks[1]<<' '<<marks[2]<<' '<<marks[3]<<' '<<marks[4]<<' '<<skill<<endl;
    }
};

class Tree{
    public:
    Student* Head;
    int size;

    Tree(){
        Head = nullptr;
    }
    void add(){
        int a,b,c,d,e,f,g; cin>>a>>b>>c>>d>>e>>f>>g;
        Student *n = new Student(a,b,c,d,e,f,g);

        if(Head == nullptr){
            Head = new Student(a,b,c,d,e,f,g);
        }
        else{
            Student *currptr = Head;
            while(currptr != NULL){
                if(*currptr < *n){
                    currptr = currptr->left;
                }
                else{
                    if(*currptr > *n){
                        currptr = currptr->right;
                    }
                    else{
                        cerr << "STUDENT WITH SAME MARKS FOUND"<<endl;
                    }
                }
            }
            currptr = new Student(a,b,c,d,e,f,g);
        }
    }
    void printInUtil(Student *nd){
        if(nd != nullptr){
            printInUtil(nd->left);
            nd->print():
            printInUtil(nd->right);
        }
    }
    void printInorder(){
        printInUtil(Head);
    }
};