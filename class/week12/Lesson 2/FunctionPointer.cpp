//왜 에러뜸??

#include <iostream>

using namespace std;

void S(int , int );
void C(int , int );
void W(int , int );
void G(int , int );
void P(int , int );



int main(){
    void (*pFunc)(int, int);  //pFunc라는 이름의 함수 포인터를 선언. 뒤는 매개변수
    pFunc = C; //함수포인터 초기화. C라는 함수의 주소를 넣는 것.
		
    int i = 1; int j = 2;
    pFunc(i, j);
    

    void (*pFuncArray[5])(int , int);

    pFuncArray[0] = S; //함수포인터 초기화. S 함수의 주소를 배열의 첫번째 요소에 할당
    pFuncArray[1] = C;
    pFuncArray[2] = W;
    
    
    pFuncArray[0](i,j); //배열의 첫번째 주소가 가리키는 함수를 호출


    return 0;
}



void S(int x, int y){
    cout <<"S = " << x+y << endl;
}


void C(int x, int y){
    cout <<"C = " << x+y << endl;
}


void W(int x, int y){
    cout <<"W = " << x+y << endl;
}


void G(int x, int y){
    cout <<"G = " << x+y << endl;
}


void P(int x, int y){
    cout <<"P" << endl;
}



