#include <iostream>

using namespace std;

class A{
public:
    char n;
    int i;
    char a;
    A(){
        printf("address: %p\n", &n);
        printf("address: %p\n", &i);
        printf("address: %p\n", &a);
    }

    void m1(){} //클래스의 크기는 멤버 함수를 생각하지 않는다. 시소떄 했던거 생각하면 됨
};

class DerivedA: public A{
public:
    int j;
    void m2(){}
};

int main(){
    //A myA;
    DerivedA myA;
    cout << sizeof(myA) << endl;
    return 0;
}
