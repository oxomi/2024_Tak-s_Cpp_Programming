//class의 상속. 크게 public Protected Private

#include <iostream>

using namespace std;

class Fish {
protected:
    bool FreshWaterFish;

public:
    //Constructor
    Fish(){} 
    //내가 생성자 오버로딩을 아래줄에서처럼 개인적으로 해줬다면 반드시 기본생성자도 적어줘야 함
    Fish(bool isFreshwater) : FreshWaterFish(isFreshwater) {}

    void swim(bool FreshWaterFish) {
        if (FreshWaterFish)
        cout << "Swim in the lake" << endl;
        else
        cout << "Swim in the sea" << endl;
    }
};

class Tuna : public Fish {
    public: // public을 해줘야 Tuna constructor 사용 가능
    using Fish::swim; 
    //함수 오버로딩을 하면 부모클래스의 함수는 hiding된다. 이를 unhide하고싶으면 이렇게 하면 된다.
    
    Tuna() : Fish(false){}

    void swim(){ //함수 오버라이딩
        //Fish::swim(); 
        cout << "Tuna swim real fast" << endl;
        //Fish::swim();
    }
};

class Carp : public Fish {
    public:
    Carp() : Fish(true){}

    void swim(){ //함수 오버라이딩
        cout << "Carp swims real slow" << endl;
    }
};

int main() {
    Carp myLunch;
    Tuna myDinner;

    myLunch.swim();
    myDinner.swim(false);
    // myDinner.Fish::swim();
    // myDinner.swim(false);

    return 0;
}