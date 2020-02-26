#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pil pair<int,long long>
using namespace std;
using namespace __gnu_pbds;

int finder;
int countsk,dval;
class Student{
    public:
    int ID, marks[5],skill;
    Student(int a,int b,int c,int d,int e, int f, int g){
        ID = a;
        marks[0] = b;
        marks[1] = c;
        marks[2] = d;
        marks[3] = e;
        marks[4] = f;
        skill = g;
    }
    bool operator< (const Student B) const {
        for(int ii=0;ii<5;ii++){
            if(marks[ii] > B.marks[ii]){return true;}
            else if(marks[ii] < B.marks[ii]){return false;}
        }
        return false;
    }
    bool lessthan(const Student B) const {
        return (skill < B.skill);
    }
    
};

bool countpred(Student A){
    if(abs(A.skill - countsk) > dval){return true;}
    return false;
}


class comp_fn{
    public:
    bool operator() ( const Student C,const Student D) const{return (C < D);}
};

typedef tree< Student , null_type, comp_fn, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree< int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;


int main()
{
    ordered_set ss;
    ordered_set2 ss2;
    map<int,Student *> m;
    string type;
    int a,b,c,d,e,f,g,h;
    while(cin >> type){
        
        if(type == "ADD"){
            cin>>a>>b>>c>>d>>e>>f>>g;
            Student *S = new Student(a,b,c,d,e,f,g);
            ss.insert(*S);
            ss2.insert(g);
            m[a]=S;
        }
        else if(type == "FIND"){
            cin>>a>>b;
            auto A = m[a];
            auto B = m[b];
            int x = abs( (int)(ss.order_of_key(*A)) - (int)(ss.order_of_key(*B)) );
            cout<<x<<endl;
        }
        else if(type == "COUNT"){
            cin>>a>>b;
            auto A = m[a];
            int sk = A->skill;
            auto one = ss2.lower_bound((sk - b));
            int onerank = (int)ss2.order_of_key(*one);
            auto two = ss2.lower_bound((sk+b));
            int tworank;
            tworank = (int)ss2.order_of_key(*two);
            if(two == ss2.end()){tworank = ss2.size();}
            // cout<<onerank<<' '<<tworank<<' '<<ss2.size()<<endl;
            cout<<(ss2.size() - (tworank - onerank))<<endl;
        }
        else if(type == "PRINT"){
            for(auto xx:ss){
                cout<<xx.ID<<' ';
            }
            cout<<endl;
        }
        else{
            cerr<<"unknown type"<<endl;
        }
    }
    

}