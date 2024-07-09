//함수 오버라이딩과 숨김처리에 관한 내용
#include <iostream>

using namespace std;

class BaseA{
public:
    void Swim(){
        cout << "AAA" <<endl;
    }
    void Swim(bool b){
        cout << "aaa" <<endl;
    }
};

class DeriveA : public BaseA{
public:
    // using BaseA::Swim; //solution 2 : unhide Swim methods in base
    void Swim(){
        cout << "BBB" <<endl;
    }
    // void Swim(bool b){} //solution 3
    void Swim(bool b){
        cout << "bbb" <<endl;
        //BaseA::Swim(b); //solution 4
    }
};

int main(){
    DeriveA myDeriveA;
    myDeriveA.Swim();
    myDeriveA.Swim(true);
    myDeriveA.BaseA::Swim(true); //solution 1

    return 0;
}


//we don't have to reimplement the same method in the DerivedA => just use BaseA