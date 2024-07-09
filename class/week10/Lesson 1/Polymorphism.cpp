//다형성

#include <iostream>

using namespace std;

class Fish{
    public:
    virtual void Swim(){
        cout << "Fish Swim" << endl;
    }
};

class Tuna: public Fish{
    public:
    void Swim(){
        cout << "Tunam Swim" << endl;

    }
};

class Carp:public Fish{
    public:
    void Swim(){
        cout << "Carp swim" << endl;
    }

};


void MakeFishSwim(Fish& InputFish){
    InputFish.Swim();
}

int main(){
    Tuna myDinner;
    Carp myLunch;

    MakeFishSwim(myDinner);
    MakeFishSwim(myLunch);

    return 0;
}

//다음차시에 이어서