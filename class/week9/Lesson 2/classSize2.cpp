#include <iostream>

using namespace std;

class A{
    public:
    char n;
    int a;
    char c;
    virtual void m1(){  //virtual 하니까 사이즈가 늘어남. 왜?

    }

};

class subA: public A{
    public:
    int k;
    virtual void m2(){
        
    }

};

int main(){
    A myA;
    subA mysubA;
    cout << sizeof(myA) << endl;
    cout << sizeof(mysubA) << endl;
    return 0;
}