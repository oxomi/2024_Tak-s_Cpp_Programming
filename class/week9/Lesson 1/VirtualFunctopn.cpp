#include <iostream>

using namespace std;

class A{
public:
    void setHappy(){}
};

class subA : public A{
public:
    virtual void setAngry();
};

int main(){
    A *p1_p1 = new A();
    A *p1_p2 = new A();

    A *p2_p1 = new subA();
    A *p2_p2 = new subA();

    void(A::*fp1)() = &A::setHappy;
    void(subA::*fp2)() = &subA::setAngry;

    printf("address: %p\n", (void*)(p1_p1->*fp1));
    printf("address: %p\n", (void*)(p1_p2->*fp1));
}

//execution code locates in the test segment => read only
//local variable needs to be writable => stack segment read/write