#include <iostream>

using namespace std;

class BaseA{
public:
    bool b;
    BaseA(){}
    BaseA(bool lsb): b(lsb) {}
};
//when its constructor is overloaded, Default BaseA() is gone
//how can we do avoid this problem?
//solution : in the derived class, we just implement "Default constructor of Derived A
//we need to call BaseA's constructor BaseA(boolean)
class DeriveA : public BaseA{
public:
    DeriveA(){}
};

int main(){
    DeriveA myDeriveA;
}


//좀 이상하게 적은듯