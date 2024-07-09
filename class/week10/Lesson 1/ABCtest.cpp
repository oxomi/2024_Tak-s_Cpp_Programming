//ABC = Abstract Base Class

#include <iostream>

using namespace std;

class ABC{
    public:
    virtual void DoSomething() = 0;

};

class Derived:public ABC{
    public:
    void DoSomething(){
        cout << "[Derived] Pure Virtual Function..." << endl;
    }
};

class Derived2: public ABC{
    public:
    void DoSomething(){
        cout << "[Derived2] Pure Virtual Function..." << endl;
    }
};


//<An Example of Polymorphism(다형성)>
void MakeDoSometing(ABC &inputABC){
    inputABC.DoSomething();
}

int main(){
    //ABC myABC;
    Derived D;
    Derived2 D2;

    D.DoSomething();
    D2.DoSomething();
    MakeDoSometing(D);
    MakeDoSometing(D2);
    return 0;
}


//virtual method <-> derived class
