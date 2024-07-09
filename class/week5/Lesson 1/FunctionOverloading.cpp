#include <iostream>
#include <functional> //function쓰기위함
#include <vector>
#include <algorithm>

using namespace std;

double Area(double R);
double Area(double R, double H);
// double Area(double R, int H);
// double Area(int R, double H);
// double Area(int R, int H);


void DisplayElementFunc(int element){
    cout << element << ' ';
}

//struct that behave as a unary function
//템플릿 : 함수나 클래스를 개별적으로 다시 정의하지 않아도, 다양한 자료형으로 사용할 수 있도록 하게 하는 것.
template<typename elementType> 
struct DisplayElement{
    void operator () (const elementType element) const{
        cout << element << ' ';
    }
};


int main(){
    vector<int> vecIntegers;
    for (int i = 0; i < 10;i++){
        vecIntegers.push_back(i);
    }
    //way 1
    for_each(vecIntegers.begin(), vecIntegers.end(), DisplayElementFunc); //STL - algorithm
    cout << endl << endl;
    //way2 (operator overloading)
    for_each(vecIntegers.begin(), vecIntegers.end(), DisplayElement<int>()); 
    cout << endl << endl;
    //way 3 (use lambda function)
    for_each(vecIntegers.begin(), vecIntegers.end(), [](int element){ cout << element << ' '; });
    cout << endl << endl;

    return 0;
}



// inline long DoubleNum(int inputNum){
//     return inputNum * 2;
// }
// // inlin don't use stack. run faster.

// double Area(double R){
//     return R *R * 3.14;
// }
// double Area(double R, double H){
//     return R * R * H * 3.14;
// }

// int main(){
//     cout << Area(2, 0) << endl;
//     cout << Area(2, 1) << endl;
//     cout << DoubleNum(4) << endl;
 
//     // //lambda expressio(람다식) : 
//     // int n = [](int x, int y) { return x + y;} (5, 4); //이게뭐노
//     // cout << n << endl;

//     // auto f1 = [](int x, int y) { return x + y;};

//     // //Assign the same lambda expression to a function object
//     // //lambda function
//     // function <int(int, int)> f2 = [](int x, int y) { return x + y; };
//     // 참고 : function <returntype(parameter)>

//     int i = 3;
//     int j = 5;

//     function<int(void)> f = [i, &j]{ return i + j; };
//     auto f1 = [](int x, int y){ return x + y; };

//     cout << f() << endl;
//     i = 22;
//     j = 44;
//     cout << f() << endl; 
//     //[i, &j]라 하면 47이 나옴!! 44+3. 레퍼런스&를 붙여줘야 새로운 값 반영이 가능하네...
//     //[&i, &j] 를 해줘야 66이 나옴.

//     cout << f1(21, 22) << endl;

//     int m = [](int x){ return [](int y){ return y * 2;}(x)+3;}(5);


//     return 0;
//     }