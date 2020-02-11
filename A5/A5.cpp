#include "A5.h"

using namespace std;

template <class T>
    Node<T>::Node(T x, Node<T> *p){
        val = x;
        next = nullptr;
        prev = p;
    }

template <class T>
    void Node<T>::setNext(Node<T> *A){
        next = A;
    }

template <class T>
    Node<T> *Node<T>::getPrev(){
        return prev;
    }

template <class T>
    T Node<T>::getVal(){
        return val;
    }
template<class T>
    Stack<T>::Stack(){
    currptr = nullptr;
    si = 0;
    }

template<class T>
    void Stack<T>::push(T x){
        if(currptr == nullptr) currptr = new Node<T>(x,nullptr);
        else {
            Node<T> *temp = new Node<T>(x,currptr);
            currptr->setNext(temp);
            currptr = temp;
        }
        si++;
    }

template<class T>
    T Stack<T>::top(){
        return currptr->getVal();
    }

template <class T>
    void Stack<T>::pop(){
        Node<T> *temp = currptr;
        currptr = currptr->getPrev();
        if(currptr != nullptr) currptr->setNext(nullptr);
        delete temp;
        si--;
    }

template <class T>
    bool Stack<T>::empty(){
        return (currptr == nullptr);
    }

template <class T>
    long long Stack<T>::size(){
        return si;
    }

template <class T>
    void Stack<T>::print(){
        Node<T> *curr = currptr;
        while(curr != nullptr){
            cout<<curr->getVal()<<' ';
            curr = curr->getPrev();
        }
        cout<<endl;
    }

void split3(const std::string& str, vector<string>& cont,char delim)
{
    std::size_t current, previous = 0;
    current = str.find(delim);
    while (current != std::string::npos) {
        cont.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delim, previous);
    }
    cont.push_back(str.substr(previous, current - previous));
}

long long convert_string_to_int(string x){
    return stoll(x, nullptr, 10);
}

void Polynomial::initCoeffs(string x){
    coeff.resize(MAX_DEGREE);
    for(long long i=0;i<MAX_DEGREE;i++){coeff[i] = 0;}

    vector<string> vec;
    split3(x,vec,' ');
    long long idx,temp;
    long long i= 0;
    for(auto x: vec){
        if(i%2 == 0){
            idx = convert_string_to_int(x);
        }
        else{
            temp = convert_string_to_int(x);
            coeff[idx]=temp;
        }
        i++;
    }
}

Polynomial Polynomial::operator+(Polynomial p){
        Polynomial result;
        for(long long i=0;i<MAX_DEGREE;i++){
            long long a=coeff[i];
            long long b = p.coeff[i];
            result.coeff.push_back(a+b);
        }
        return result;
}
Polynomial Polynomial::operator-(Polynomial p){
        Polynomial result;
        for(long long i=0;i<MAX_DEGREE;i++){
            long long a=coeff[i];
            long long b = p.coeff[i];
            result.coeff.push_back(a-b);
        }
        return result;
}
Polynomial Polynomial::operator*(Polynomial p){
        Polynomial result;
        for(long long i=0;i<MAX_DEGREE;i++){result.coeff.push_back(0);}

        for(long long i=0;i<ceil(MAX_DEGREE/2.0);i++){
            long long a=coeff[i];
            if(a != 0){
                for(long long j=0;j<ceil(MAX_DEGREE/2.0);j++){
                    long long b=p.coeff[j];
                    if(b != 0){
                        result.coeff[(i+j)] += (a*b);
                    }
                }
            }
        }
        return result;
}
char Polynomial::sign(long long x){
    if(x < 0){return '-';}
    return '+';
}
void Polynomial::print(){
    long long i=0;
    long long x=0;
    while((x<1) && (i<MAX_DEGREE)){
        long long a = coeff[i];
        if(a != 0){
            cout<<(a)<<"x^"<<i;
            x++;
        }
        i++;
    }
    while((i<(MAX_DEGREE))){
        long long a = coeff[i];
        if(a != 0){
            cout<<' '<<sign(a)<<' '<<abs(a)<<"x^"<<i;
        }
        i++;
    }
    cout<<endl;
}

long long precedence(char op){ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*') 
    return 2; 
    if(op == '/')
    return 3;
    return 0; 
} 

vector<string> takeIntInput() {

    std::string line;
    string token;
    std::cin.ignore();
    std::getline(std::cin, line);

    std::stringstream ss(line);
    vector<string> tokenvec;
    split3(line,tokenvec,' ');
    return tokenvec;
}

vector<string> takePolyInput() {
    long long num;
    std::cin >> num;
    vector<string> res;
    std::string line;

    std::cin.ignore();

    for(long long i = 0; i < num; i++) {
        std::getline(std::cin, line);

        res.push_back(line);
    }
    return res;
}

template <class T>
T solve(T num1,T num2, char op){
    switch(op){
        case '+': return (num1 + num2);
        case '-': return (num1 - num2);
        case '*': return (num1 * num2);
        default : return (num1);
    }
}


template <class T>
void process(Stack<T> &num, Stack<char> &symb){
    T num1 = num.top();
    num.pop();
    T num2 = num.top();
    num.pop();
    char op = symb.top();
    symb.pop();
    T res = solve(num2,num1,op);
    num.push(res);
}

void evaluateint(){
    long long i; 
    Stack <long long> values; 
    Stack <char> ops;
    vector<string> tokenvec = takeIntInput();
    tokenvec.insert(tokenvec.begin(),"(");
    tokenvec.push_back(")");    
    for(auto a : tokenvec){ 
        if(a == "("){ 
            ops.push(a[0]); 
        } 
        else if(a == ")") 
        { 
            while(!ops.empty() && ops.top() != '(') 
            { 
                process(values,ops); 
            } 
            if(!ops.empty()) 
               ops.pop(); 
        } 
        else if((a == "+") || (a == "-") || (a == "*"))
        { 
            while(!ops.empty() && precedence(ops.top()) >= precedence(a[0])){ 
                process(values,ops); 
            } 
            ops.push(a[0]); 
        } 
        else { 
            long long val = convert_string_to_int(a); 
            values.push(val); 
        } 
        // if(!values.empty()) values.print();
        // if(!ops.empty()) ops.print();
    } 
    while(!ops.empty()){ 
        process(values,ops); 
    } 
      
   
    cout<<values.top()<<endl;  
}
void evaluatepoly(){
    Stack <Polynomial> values; 
    Stack <char> ops;
    vector<string> tokenvec = takePolyInput();
    tokenvec.insert(tokenvec.begin(),"(");
    tokenvec.push_back(")");
    for(auto a : tokenvec){ 
        if(a == "("){ 
            ops.push(a[0]); 
        } 
        else if(a == ")") 
        { 
            while(!ops.empty() && ops.top() != '(') 
            { 
                process(values,ops); 
            } 
            if(!ops.empty()) 
               ops.pop(); 
        } 
        else if((a == "+") || (a == "-") || (a == "*"))
        { 
            while(!ops.empty() && precedence(ops.top()) >= precedence(a[0])){ 
                process(values,ops); 
            } 
            ops.push(a[0]); 
        } 
        else { 
            Polynomial P;
            P.initCoeffs(a);
            values.push(P);
        } 
    } 
    while(!ops.empty()){ 
        process(values,ops); 
    } 
      
   
    values.top().print();
}
int main() {
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */   
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