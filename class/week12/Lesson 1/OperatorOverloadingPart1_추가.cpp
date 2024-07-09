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



    // 추가) operator와 this 에 대해서 설명하심
    // >, >= 등의 대소비교와 this, parameter의 관계
    // 깊은복사, 얕은복사

    //this this
    // H = H + 3
    // 1. Date operator+= (int i)
    // 1. Date&
    // 3. void  <<- is better!
    Date operator+(int DaysToAdd){
        Date newDate(D + DaysToAdd, M, Y);  
        return newDate;                     
    }

    Date operator-(int DaysToSub){
        // Date newDate(D - DaysToSub, M, Y);  //does not look cool
        // return newDate;                     //does not look cool

        return Date(D - DaysToSub, M, Y);

    }

    Date& operator+=(int DaysToAdd) {
        D += DaysToAdd;
        return *this;
    }


    //void 관련 설명은 못적음 ㅜㅜ



    friend ostream& operator << (ostream& os, const Date& myH); 


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

    Date PreviousHoliday(H + 10);
    PreviousHoliday.Display();
    
    Date PreviousHoliday2(H - 10);
    PreviousHoliday2.Display();

    H += 5;
    H.Display();

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

