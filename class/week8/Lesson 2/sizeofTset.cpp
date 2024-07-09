#include <iostream>

using namespace std;

class MyString{
    private:
    char *Buffer;
    int Length;
};

class Human{
    public:
    int Age;
    bool Gender;
    MyString myString;

    public:
    Human(){cout << "Constructor is called" << endl;}

};

int main(){
    Human Tom;
    cout << sizeof(MyString) << endl; //16
    cout << sizeof(Human) << endl;  //24
    cout << sizeof(Tom) << endl;  //24
}

//Depending on the compiler you use, sizeof() might or might not include padding for certain attributes on word boundaries.
//중요) what is padding? and how can we guess the classes size? => 
//Note that member functions and their local variables(멤버함수 안의 또다른 변수) do not play a role in defining the sizeof() a class.


