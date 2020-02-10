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

int precedence(char op){
    switch(op){
        case '+': return 2; break;
        case '-': return 1; break;
        case '*': return 3; break;
        default: return 0; break;
    }
}
vector<char> takeIntInput() {

    vector<char> res;
    std::string line, token;
    std::cin.ignore();
    std::getline(std::cin, line);

    std::stringstream ss(line);
    
    while(ss >> token) {
        res.push_back(token);
        // process each token
        // this will either be an operator, a parenthesis or an integer
    }
    return res;
}

vector<vector<char> > takePolyInput() {
    int num;
    std::cin >> num;
    vector<vector<char> > res;
    std::string line;

    std::cin.ignore();

    for(int i = 0; i < num; i++) {
        std::getline(std::cin, line);

        if(line.size() == 1) {
            vector<char> temp;
            temp.push_back(line[0]);
            res.push_back(temp);
            // process the line
            // this will be either an operator or a parenthesis
        }
        else {
            // this will be a polynomial
            std::stringstream ss(line);

            int exponent;
            long long coeff;
            vector<char> temp;
            while(ss >> exponent, ss >> coeff) {
                temp.push_back(exponent);
                temp.push_back(coeff);
                // process the exponent and coefficient appropriately
            }
            res.push_back(temp);

        }
    }
}

int solve(int num1,int num2, char op){
    switch(op){
        case '+': return (num1 + num2);
        case '-': return (num1 - num2);
        case '*': return (num1 * num2);
    }
}

void process(Stack<int> num, Stack<char> symb){
    int num1 = num.front();
    num.pop();
    int num2 = num.front();
    num.pop();
    char op = symb.front();
    symb.pop();
    int res = solve(num1,num2,op);
    num.push(res);
}

void evaluateint(){
    Stack<int> num;
    Stack<char> symb;

    vector<char> tokens = takeIntInput();

    int result;
    for(auto x:tokens){
        if((x >=' 0') && (x<='9')) num.push((x-'0'));
        else if((x=='+') || (x=='-') || (x=='*')){
            if(symb.empty()) symb.push(x);
            else{
                if(precedence(x) > precedence(symb.front())) symb.push(x);
                else while(precedence(x) < precedence(symb.front())) process(num,symb);
            }
        }
        else{
            if(x == '(') symb.push(x);
            else if(x == ')'){
                while(symb.front() != '(') process(num,symb);
                symb.pop();
            }
        }
    }
    if(!num.empty()){
        while(!symb.empty()) process(num,symb);
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