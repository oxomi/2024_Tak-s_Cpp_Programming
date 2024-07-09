#include <iostream>
using namespace std;

class Motor{
    public:
    void SwitchIgnition(){
        cout << "Ignition On" <<endl;
    }
    void PumpFuel(){
        cout << "Fuel in Cylinders" << endl;
    }
    void FireCylinders(){
        cout << "Vroom" << endl;
    }
};

class Car : protected Motor //프라이빗으로 하니까 오류나는거같음
{
    public:
    void Move(){
        SwitchIgnition();
        PumpFuel();
        FireCylinders();
    }
};
//사진참고해서 더적어야함

int main(){
    Car myDreamCar;
    myDreamCar.Move();
    myDreamCar.PumpFuel();
    return 0;
}
