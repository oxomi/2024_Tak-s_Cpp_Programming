#include <iostream>

using namespace std;

class A{
    public:
    int Age;
    A(){cout << "A constructor" <<endl;}
};

class B : public virtual A{
    public:
    B(){cout << "B constructor" <<endl;}

};

class C : public virtual A{
    public:
    C(){cout << "C constructor" <<endl;}
};

class D : public virtual A{
    public:
    D(){cout << "D constructor" <<endl;}
};

class BCD : public B, public C, public D{
    public:
    BCD(){cout << "BDC constructor" <<endl;}
};

int main(){
    BCD myBCD;
    myBCD.Age = 10;
    return 0;
}

//Do not make "Multiple" Inheritance(상속) relationship in your o_o project 
//when you join some project at your company