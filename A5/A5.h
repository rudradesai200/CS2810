#include <bits/stdc++.h>

#define MAX_DEGREE 10

using namespace std;

template<class T>
class Node {
    private:
        T val;                                      //stores value
        T *next, *prev;                             //stores links to next and prev pointers

    public:
        Node(T x, T *p);                            //constructor
        void setNext(const Node<T> *A);             //sets Next pointer
        Node* getPrev();                            //returns Prev pointer
};

template <class T>
class Stack{
    private:
        Node<T> *currptr;                           //stores the top of the stack
    
    public:
        Stack();                                    //Constructor for stack class
        void push(T x);                             //Pushes element on stack
        T front();                                  //returns the top element on stack
        void pop();                                 //removes the top of the stack
        bool empty();                               //check for isEmpty()
};

class Polynomial{
public:
    int si;
    vector<double> coeff;
    
    void initCoeffs();                              //to initialize coeffecients
    Polynomial operator+(Polynomial p);             //operator overloading +
    Polynomial operator-(Polynomial p);             //operator overloading -
    Polynomial operator*(Polynomial p);             //operator overloading *
    char sign(double x);                            //sign type return
    void print();                                   //printing Polynomial

};

int precedence(char op);                            //returns precedence of operators

vector<char> takeIntInput();                        //takes int input
vector<vector<char> > takePolyInput();              //takes polynomial input

int solve(int num1,int num2, char op);              //gives result of (num1 op num2)
void process(Stack<int> num, Stack<char> symb);     //processes one step of operation
void evaluateint();                                 //evaluate the given expression for int
void evaluatepoly();                                //evaluates the given expression for polynomial
