#include <bits/stdc++.h>

#define MAX_DEGREE 10

using namespace std;

template<class T>
class Node {
    private:
        T val;                              //stores value
        T *next, *prev;                     //stores links to next and prev pointers

    public:
        Node(T x, T *p);                    //constructor
        void setNext(const Node<T> *A);     //sets Next pointer
        Node* getPrev();                    //returns Prev pointer
};

template <class T>
class Stack{
    private:
        Node<T> *currptr;                   //stores the top of the stack
    
    public:
        Stack();                            //Constructor for stack class
        void push(T x);                     //Pushes element on stack
        T front();                          //returns the top element on stack
        void pop();                         //removes the top of the stack
        bool empty();                       //check for isEmpty()
};

class Polynomial{
public:
    int si;
    vector<double> coeff;
    
    void initCoeffs();                      //to initialize coeffecients
    Polynomial operator+(Polynomial p);     //operator overloading +
    Polynomial operator-(Polynomial p);     //operator overloading -
    Polynomial operator*(Polynomial p);     //operator overloading *
    char sign(double x);                    //sign type return
    void print();                           //printing Polynomial

};

int precedence(char op){                    //returns precedence of operators
    switch(op){
        case '+': return 2; break;
        case '-': return 1; break;
        case '*': return 3; break;
        default: return 0; break;
    }
}
void takeIntInput();                        //takes int input
void takePolyInput();                       //takes polynomial input

void evaluateint();                         //evaluate the given expression for int
void evaluatepoly();                        //evaluates the given expression for polynomial
