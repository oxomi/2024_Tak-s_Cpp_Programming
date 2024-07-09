#include <iostream>

using namespace std;

class A{
    public:
    virtual void Swim(){

    }
};

class B : public A{
    public:
    void Swim() override final{};
};

class C : public B{
    public:
    //void Swim() override {};  ? 그래서 어케해결하는디요 이거
};

int main(){

}