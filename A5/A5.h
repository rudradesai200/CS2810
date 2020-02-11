#include <bits/stdc++.h>
#define MAX_DEGREE 100

using namespace std;

template<class T>
class Node {
    private:
        T val;                                      //stores value
        Node *next, *prev;                             //stores links to next and prev pointers

    public:
        Node(T x, Node *p);                            //constructor
        void setNext(Node *A);                   //sets Next pointer
        Node* getPrev();                            //returns Prev pointer
        T getVal();                                 //returns the value stored in the node
};

template <class T>
class Stack{
    private:
        Node<T> *currptr;   
        long long si;                        //stores the top of the stack
    
    public:
        Stack();                                    //Constructor for stack class
        void push(T x);                             //Pushes element on stack
        T top();                                  //returns the top element on stack
        void pop();                                      //removes the top of the stack
        bool empty();                               //check for isEmpty()
        long long size();
        void print();
};

long long convert_string_to_int(string x);

class Polynomial{
public:
    long long si;
    vector<long long> coeff;
    
    void initCoeffs(string x);                              //to initialize coeffecients
    Polynomial operator+(Polynomial p);             //operator overloading +
    Polynomial operator-(Polynomial p);             //operator overloading -
    Polynomial operator*(Polynomial p);             //operator overloading *
    char sign(long long x);                            //sign type return
    void print();                                   //printing Polynomial

};

void split3(const std::string& str, vector<string>& cont,char delim = ' ');

long long precedence(char op);                            //returns precedence of operators

vector<string> takeIntInput();                        //takes int input
vector<string> takePolyInput();              //takes polynomial input

template <class T>
T solve(T num1,T num2, char op);              //gives result of (num1 op num2)

template <class T>
void process(Stack<T> &num, Stack<char> &symb);     //processes one step of operation



void evaluateint();                                 //evaluate the given expression for int
void evaluatepoly();                                //evaluates the given expression for polynomial
