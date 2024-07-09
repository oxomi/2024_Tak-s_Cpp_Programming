//friend로 선언된 것은 class의 private, protected에 접근할 수 있다.

#include <iostream>
#include <stdio.h>

using namespace std;

class Human{
    private:
    int Age;
    string Name;

    public:
    Human(string InputName, int InputAge){
        Name = InputName;
        Age = InputAge;
    }

    friend void DisplayAge(const Human& Person);
};


class Utility{
    public:
    static void DisplayAge(const Human& Person){
        //cout << Person.Age << endl; 
    }
};


void DisplayAge(const Human& Person){
    cout << Person.Age << endl; //friend 안해주면 프라이빗변수 age에 접근 불가.
}

int main(){
    Human Tom("Tom", 25);
    DisplayAge(Tom);
    Utility::DisplayAge(Tom);
    return 0;
}

//오류 해결 안했는데 다음 파일로 넘어감.. 원인은 내가 찾자.