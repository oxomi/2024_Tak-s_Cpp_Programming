#include <iostream>

using namespace std;

class F{
    public:
    F() {cout << "Constructed F" << endl;}
     ~F() {cout<< "Destructed F" <<endl;}  //가상 소멸자로 선언하지 않으면 문제가 발생. 왜?

};

class T:public F{
    public:
    T() {cout << "Constructed T" <<endl;}
    ~T() {cout << "Destructed T" <<endl;}

};

void DeleteFMemory(F *pF){
    delete pF;
}

int main(){
    T  *pT = new T;
    cout << "Deleting T..." << endl;
    DeleteFMemory(pT);
    return 0;
}

//keep in mind. Destructor of Base class => needs to be declared as "virtual"