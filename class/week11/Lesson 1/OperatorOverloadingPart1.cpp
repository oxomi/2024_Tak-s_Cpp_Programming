#include <iostream>
#include <sstream>
#include <string>
#include <memory>

using namespace std;

class Date{
    private:
    int D;
    int M;
    int Y;
    string DateInString;

    public:
    //Constructor
    Date(int iD, int iM, int iY): D(iD), M(iM), Y(iY) {};  //inputDay ..

    //인스턴스를 ++해주기 위해 ++연산자 오버로딩
    Date &operator ++(){ //참조자 있고 없고가 무슨 차이지...
        ++D;
        return *this;
    }
    //--연산자 오버로딩
    Date &operator --(){ 
        --D;
        return *this;
    }

    Date operator ++(int){
        Date Copy(D, M, Y);
        ++D;
        return Copy;
    }
    friend ostream& operator << (ostream& os, const Date& myH); 
    //friend는 멤버함수가 아니기 떄문에 프라이빗 변수에 접근할 수 없다. 

    // operator const char*(){
    //     ostringstream fD;
    //     fD << D << "/" << M << "/" << Y << endl;
    //     DateInString = fD.str();
    //     return DateInString.c_str();
    // }

    void Display(){
        cout << D << "/" << M << "/" << Y << endl;
    }

};

ostream& operator << (ostream& os, const Date& myH){
    return os << myH.D << "/" << myH.M << "/" << myH.Y;
}


int main(){
    Date H(15, 5, 2024);
    H.Display();
    cout << H++ << endl;

    //smart pointer..?
    unique_ptr<Date> pHoliday(new Date(25, 12, 2024)); //include <memory>
    pHoliday->Display();

    // H.Display();
    // ++H; //인스턴스를 operand로 넣기 위해 ++연산자를 오버로딩하기
    // H.Display();
    // --H;
    // H.Display(); 
    // H++;
    // H.Display();
    return 0;
}

//// how to increment
// (1) reference
// (2) copy of something