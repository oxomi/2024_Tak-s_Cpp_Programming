//explicit(명시적)
//implicit(묵시적)

#include <iostream>
using namespace std;

class A{
    public:
    int age;
    int height;

    A(){ cout << "Default A is Created" << endl;}
    A(int myAge){
        age = myAge;
        cout << "A is Created" << endl;
    }
};

int main(){
    A myA = 11; //explicit conversion
    A myA2;

    cout << myA.age <<  endl;
    myA2 = 11; //implicit conversion
    cout << myA2.age << endl;
    return 0;
}