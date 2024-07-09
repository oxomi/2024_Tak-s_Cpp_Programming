#include <iostream>

#include <string>

#include <initializer_list>  // No #include<string>

using namespace std;

class E {

    private:

        string fn;

        string ln;

    public:

        E(string f, string l): fn(f), ln(l) {

        }

        string gfn() {

            return fn + " " + ln;

        }

// Implement this part

        virtual ~E() { 
        }
        //소멸자를 가상 함수로 선언하면 동적 바인딩에 의해 기본 클래스의 소멸자에 대한 호출이 종속클래스의 소멸자에 대한 호출로 변경되어, 
        //종속 클래스의 소멸자들이 실행된 후 기본 클래스의 소멸자가 순서대로 실행된다.

        virtual void pw()=0; 
        //출력과 관련된 함수.
        //순수 가상함수 : 코드가 없고 선언만 있는 가상 함수. 
        //목적 - 해당 클래스에서 실행하는 것이 목적이 아닌, 종속 클래스에서 재정의하여 구현할 함수를 알려주는 인터페이스의 역할을 한다고 보면 된다.
};



class HE: public E {

    private:

        double hw;

    public:

        // Implement this part
        HE(string f, string l, double h): E(f, l), hw(h){} //!

        ~HE() override {}  //가상 소멸자 오버라이딩 방식.

        void pw() override {
            cout << "HaHa " << gfn() << " is " << hw << endl;
        }

};



class RE: public E {

    private:

        double mw;

    public:

        // Implement this part
        RE(string f, string l, double m): E(f, l), mw(m){}

        ~RE() override {} //가상 소멸자 오버라이딩

        void pw() override {
            cout << "HoHo " << gfn() << " is " << mw << endl;
        }

};

int main() {

    initializer_list<E*> Es = {new HE("Super", "Sonic", 11.5), new RE("One", "Piece", 1310.4)};        // No array
    //initializer_list를 사용하여 초기화 '리스트' 생성하고, 이를 Es라는 변수에 할당한다.
    //즉 Es는 HE, RE 객체의 포인터를 저장하고 있다.


    for(E* E: Es) { 

        E->pw();

    }
    //범위 기반 for루프.
    //이 루프는 Es라는 컨테이너의 모든 요소에 대한 반복작업을 한다.
    //이때마다 루프 변수인 E에는 Es에 들어있는 각 요소들에 대한 참조 또는 복사본이 할당된다. 
    //즉 Es에 있는 모든 E* 타입의 객체를 차례대로 가져와서 본문을 실행한다.

    return 0;

}