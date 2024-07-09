#include<iostream>
using namespace std;

class Simple{
    public:
        int i = 10;
        int j = 20;
        void Setl(int i)
        {
            // i = i;
            //this pointer가 붙은 변수는 클래스의 멤버변수이다. 
            //클래스의 멤버함수 내부의 모든 멤버변수 앞에는 컴파일러를 통해 자동으로 this가 붙는다.
            //그러나 멤버변수와 그냥 변수를 구분하기 어려운 상황에서는 명시적으로 붙여주기도 한다.
            //밑의 코드에서 후자의 i는 멤버변수가 아닌 함수의 매개변수 i이다.
            this->i = i;
            this->j = i;
        }
};

int main(){
    Simple S;
    S.Setl(11);
    cout << S.i << endl;
    return 0;
}