#include<iostream>
using namespace std;

class SimpleCat{
private:
int itsAge;
public:
    SimpleCat();
    SimpleCat(SimpleCat&);
    ~SimpleCat();

    int GetAge() const {return itsAge;}
    void SetAge(int age) {itsAge = age;}

};

SimpleCat::SimpleCat() //생성자
{
    cout << "Simple Cat Constructor..." << endl;
    itsAge = 1;
}
SimpleCat::SimpleCat(SimpleCat&) //복사 생성자
{
    cout << "Simple Cat Copy Constructor..." << endl;
}
SimpleCat::~SimpleCat() //소멸자
{
    cout << "Simple Cat Destructor..." << endl;
}


const SimpleCat & FunctionTwo(const SimpleCat & theCat);



int main(){
    cout << "Malking a cat..." << endl;
    SimpleCat Frisky;
    cout << "Frisky is " << Frisky.GetAge() << "  years old" << endl;
    int age = 5;
    Frisky.SetAge(age);
    cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
    cout << "Calling FunctionTwo..." << endl;
    FunctionTwo(Frisky);
    cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;

    return 0;
}


//functionTwo, passes a ref to a  const
const SimpleCat & FunctionTwo(const SimpleCat & theCat)
{
    cout << "Function Two. Returning..." << endl;
    cout << "Frisky is now " << theCat.GetAge();
    cout << " years old " << endl;

    return theCat;
}