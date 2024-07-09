#include<iostream>
using namespace std;

int &Getint();

int main(){
    cout << "Hello World!" << endl;
    int & rint = Getint();
    cout << rint << endl;
    return 0;
}

// int &Getint(){
//     int nLocalint = 25;
//     return nLocalint; 
// }
//warning: nLocalint는 함수 내에서 선언된 지역변수이므로 함수가 종료될 때 스텍에서 지워짐.
//따라서 라인8~9에서 이 지역변구에 대한 참조를 반환하려 하면 더이상 유효하지 않은 메모리에 접근하게 됨.

int &Getint(){
    int *pInteger = new int(25); //따라서 동적으로 메모리를 할당하고 그 메모리의 주소에 들어있는 값을 반환하도록 함.
    return *pInteger;
}