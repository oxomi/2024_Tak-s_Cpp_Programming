#include <iostream>

using namespace std;

class F{
    public:
    //base class must declare "virtual"
    virtual void Swim() {cout << "F swims!" << endl;}
};

class T : public F{
    //override: Explicitly specify "override"
    //void Swim() const override {cout << "T Swims!" <<endl;} //swim함수를 덮어쓰기 하는 것.
    void Swim() const {cout << "T Swims!" <<endl;}  //새로운 swim함수를 만드는 것. 위의 swim함수와 다름
};


int main(){
    return 0;
}



//void Swim()
//void Swim() const
//-> different method!
