#include "A5.h"
#include<bits/stdc++.h>

using namespace std;
template <class T>
    Node<T>::Node(T x, T *p){
        val = x;
        next = nullptr;
        prev = p;
    }

template <class T>
    void Node<T>::setNext(const Node<T> *A){
        next = A;
    }

template <class T>
    Node<T> *Node<T>::getPrev(){
        return prev;
    }

template<class T>
    Stack<T>::Stack(){
    currptr = nullptr;
    }

template<class T>
    void Stack<T>::push(T x){
        if(currptr == nullptr) currptr = new Node<T>(x,nullptr);
        else {
            Node<T> *temp = new Node<T>(x,currptr);
            currptr->setNext(temp);
            currptr = temp;
        }
    }

template<class T>
    T Stack<T>::front(){
        return *currptr;
    }

template <class T>
    void Stack<T>::pop(){
        Node<T> *temp = currptr;
        currptr = currptr->getPrev();
        currptr->setNext(nullptr);
        delete temp;
    }

template <class T>
    bool Stack<T>::empty(){
        return (currptr == nullptr);
    }

void Polynomial::initCoeffs(){
    coeff.resize(MAX_DEGREE);
    for(int i=0;i<MAX_DEGREE;i++){coeff[i] = 0;}

    double temp;
    int idx;
    while(cin>>idx>>temp){
        coeff[idx]=temp;
    }
}

Polynomial Polynomial::operator+(Polynomial p){
        Polynomial result;
        for(int i=0;i<MAX_DEGREE;i++){
            double a=coeff[i];
            double b = p.coeff[i];
            result.coeff.push_back(a+b);
        }
        return result;
}
Polynomial Polynomial::operator-(Polynomial p){
        Polynomial result;
        for(int i=0;i<MAX_DEGREE;i++){
            double a=coeff[i];
            double b = p.coeff[i];
            result.coeff.push_back(a-b);
        }
        return result;
}
Polynomial Polynomial::operator*(Polynomial p){
        Polynomial result;
        for(int i=0;i<MAX_DEGREE;i++){result.coeff.push_back(0);}

        for(int i=0;i<ceil(MAX_DEGREE/2);i++){
            double a=coeff[i];
            if(a != 0){
                for(int j=0;j<ceil(MAX_DEGREE/2);j++){
                    double b=p.coeff[j];
                    if(b != 0){
                        result.coeff[i+j] += (a*b);
                    }
                }
            }
        }
        return result;
}
char Polynomial::sign(double x){
    if(x < 0){return '-';}
    return '+';
}
void Polynomial::print(){
    int i=0;
    int x=0;
    while(x<1){
        double a = coeff[i];
        if(a != 0){
            cout<<(a)<<"x^"<<i<<' ';
            x++;
        }
        i++;
    }
    while((i<(MAX_DEGREE))){
        double a = coeff[i];
        if(a != 0){
            cout<<sign(a)<<' '<<abs(a)<<"x^"<<i<<' ';
        }
        i++;
    }
    cout<<endl;
}

void takeIntInput() {

    std::string line, token;
    std::cin.ignore();
    std::getline(std::cin, line);

    std::stringstream ss(line);
    
    while(ss >> token) {
        // process each token
        // this will either be an operator, a parenthesis or an integer
    }
}

void takePolyInput() {
    int num;
    std::cin >> num;

    std::string line;

    std::cin.ignore();

    for(int i = 0; i < num; i++) {
        std::getline(std::cin, line);

        if(line.size() == 1) {
            // process the line
            // this will be either an operator or a parenthesis
        }
        else {
            // this will be a polynomial
            std::stringstream ss(line);

            int exponent;
            long long coeff;
            while(ss >> exponent, ss >> coeff) {
                // process the exponent and coefficient appropriately
            }

        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;cin>>N;
    while(N--){
        string typ;cin>>typ;
        if(typ == "int"){
            evaluateint();
        }
        else if (typ == "poly"){
            evaluatepoly();
        }
    }
    return 0;
}