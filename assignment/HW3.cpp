
#include <iostream>

#include <stdio.h>

using namespace std;

//static 멤버변수: 모든 객체가 한 메모리를 공유하는 멤버 변수. 모든 객체가 공유하는 멤버다.
//static 멤버 변수는 모든 객체가 공유해야 하므로 프로그램 전체 영역에서 메모리 유지가 되야 한다. 
//따라서 반드시 전역 범위에서 정의 및 초기화를 해주어야 한다.
class HW3 {

public:
    static int count; 
    //단순 선언. 메모리를 사용하지는 않음
    //클래스 내에서 초기화를 하면 객체를 생성할 때마다 변수값이 게속 덮어씌워지기 때문에 안된다.

    HW3(){}
    
    HW3(const HW3& t_hw1) { //복사생성자
        cout << "Run " << count << endl;
    }

    HW3 & operator=(const HW3& t)  
    {

        cout << "Run " << count++ << endl;

        return *this;

    }

};

int HW3::count = 1000; //전역 범위에서 정의 및 초기환

int main()

{

    HW3 hw1, hw2;

    hw2 = hw1; // 이미 생성된 두 객체에 '=' 연산 하는 것 -> 오버로딩한 대입연산자 '=' 호출

    HW3 hw3 = hw1; //대입을 이용한 방식으로 객체를 생성하는 것 -> HW3 HW3(HW1) 으로 묵시적 변환이 일어나 복사 생성자가 호출.

    return 0;

}

