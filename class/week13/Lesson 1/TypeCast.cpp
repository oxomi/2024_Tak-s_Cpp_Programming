//static_cast

#include <iostream>

using namespace std;

class Base{

};

class Derived : public Base{

};

class CUnrelated{


};

class F{
    public:
    virtual void Swim() { cout << "F smins in water" << endl;}
};

class T : public F{
    public: 
    void Swim(){cout << "T swims in sea" << endl;}
    void BecomeDinner() { cout << "Dinner in Sushi" << endl;}
};

class C : public T{
    public: 
    void Swim(){cout << "C swims in lake" << endl;} 
    void Talk(){cout << "Talk" << endl;}
};

void DetectFishType(F* InputFish) {
    T* plsT = dynamic_cast<T*>(InputFish);  //if conversion is successful, plsT will be not NULL
    if(plsT){
        cout << "Detected T" << endl;
        plsT->BecomeDinner();
    }
    C* plsC = dynamic_cast<C*>(InputFish);
    if(plsC){
        cout << "Detected C" << endl;
        plsC->Talk();
    }
}

class SomeClass{
    public:
    int i;
    void DisplayMembers(){cout << i << endl;}
};

void DisplayAllData(const SomeClass& mData){
    //mData.DisplayMembers();
    SomeClass& refData = const_cast<SomeClass&>(mData);
    refData.DisplayMembers();
}

void DisplayAllData2(const SomeClass& pData){
    //mData.DisplayMembers();
    SomeClass& refData = const_cast<SomeClass&>(pData);
    refData->DisplayMembers();
}



int main(){
    char *pS = "Hello World";
    int *pB = (int *)pS;

    Base *pBase = new Derived(); //Dericed -> Base OK
    //Derived* pDerived = pBase; // Base -> Derived; Not OK
    Derived* pDerived = static_cast<Derived*>(pBase); //Need type case at compile time. Why? we got an error AT COMPILE TIME!!
    //Try yo C-style Typecast
    Derived* pDerived = (Derived*)pBase; // C-style cast it still OK
    //CUnrelated* pUnrelated = pBase;
    //CUnrelated* pUnrelated = static_cast<CUrelated*>(pBase);
    CUnrelated* pUnrelated = reinterpret_cast<CUnrelated*>(pBase);
    double dPi = 3.14159265;
    int Num = dPi;
    int Num2 = static_cast<int>(dPi);

    C mylunch;
    T myDinner;

    DetectFishType(&myDinner);
    DetectFishType(&mylunch);

    F* pF = new F();
    char* pBytes = (char*)pF;
    char* pBytes2 = reinterpret_cast<char*>(pF);

    return 0;
}