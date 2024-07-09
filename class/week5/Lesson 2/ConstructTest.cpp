#include <iostream>
#include <string>

using namespace std;

class Human{
    // private:
    //     int Age;
    //     string Name;
        

    public:
        int Age;
        string Name;
        // Human(){}
        // //overloaded constructor
        // Human(int HumanAge){
        //     Age = HumanAge;
        // }

        Human(string HumanName = "Aimyong", int HumanAge = 24){
            Name = HumanName;
            Age = HumanAge;
        }

        ~Human(){
            cout << "Destructor is called..." << endl;
        }
};

int main(){
    // Human Eve(21);
    // cout << Eve.Age;
    // Human Ive("Ive", 21);
    // cout << Ive.Name << endl;
    // cout << Ive.Age << endl;

    // Human Twix("Twix");
    // cout << Twix.Name << endl;
    // cout << Twix.Age << endl;
    // Human Jenny("Jenny", 25);
    // cout << Jenny.Name << endl;
    // cout << Jenny.Age << endl;

    Human Aimyong;
    cout << Aimyong.Name << endl;
    cout << Aimyong.Age << endl;
    Human IU("LU", 31);

    return 0;
}