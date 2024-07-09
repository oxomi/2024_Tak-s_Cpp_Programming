#include<iostream>
using namespace std;

class Human{
    public:
        int age;
    public:
    Human(int HumanAge): age(HumanAge){} //축약형
};

void DoSomething(Human person){
    cout << "Humans sent did something" << endl;
}

int main(){
    Human Kid(10);
    // Human anotherKid = 11;
    // cout << anotherKid.age << endl;
    // DoSomething(10);
    return 0;
}

//새로 올라온 10-1 피피티
//union classtype

