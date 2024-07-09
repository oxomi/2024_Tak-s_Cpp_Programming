//왜 에러뜸??

#include <iostream>

using namespace std;

void S(int &, int &);
void C(int &, int &);
void W(int &, int &);
void G(int &, int &);
void P(int &, int &);



int main(){
    void (*pFunc)(int&, int&);
    const int MAXArray = 5;
    void (*pFuncArray[MAXArray])(int &, int&);
    pFunc = C;
    int i = 1; int j = 2;
    pFunc(i, j);
    pFuncArray[0] = S;
    pFuncArray[1] = C;
    pFuncArray[2] = W;


    return 0;
}



void S(int x, int y){
    cout <<"S" << endl;
}


void C(int x, int y){
    cout <<"C" << endl;
}


void W(int x, int y){
    cout <<"W" << endl;
}


void G(int x, int y){
    cout <<"G" << endl;
}


void P(int x, int y){
    cout <<"P" << endl;
}



