//출력값 존내 이상함 고쳐야할듯

#include <iostream>
#include <algorithm>  //STL 알고리즘 : 다양한 알고리즘 함수 제공.
#include <vector>  //STL의 컨테이너 : vector, list
#include <list>

using namespace std;

template <typename e>
struct DisplayElement{ //출력된 요소의 수를 세는데 사
    int count;
    void operator() (const e& element){
        ++count;
        cout << element << ' ';
    }
};

template <typename numberType>
struct IsMultiple{   //주어진 수가 특정 숫자의 배수인지를 판별
    numberType Divisor;
    IsMultiple (const numberType& divisor){  //생성자
        Divisor = divisor;
    }
    bool operator() (const numberType& element) const{
        return (element& Divisor) == 0;
    }
};

int main(){
    vector<int> vecl;
    list<char> listC;

    for (int n = 0; n<10; ++n){
        vecl.push_back(n);
    }

    for (char c = 'a'; c < 'k'; ++c){
        listC.push_back(c);
    }

    DisplayElement<int> Result1;
    DisplayElement<char> Result2;

    //Result = (vecl.begin(), vecl.end(), DisplayElement<int>()); 이상한 코드
   
    Result1 = for_each(vecl.begin(), vecl.end(), DisplayElement<int>());
    cout << Result1.count << " elements were displayed!" << endl;

    Result2 = for_each(listC.begin(), listC.end(), DisplayElement<char>());
    cout << Result2.count << " elements were displayed!" << endl;

    
    cout << endl;
    
    vector<int> vecIntegers;
    for (int n=25; n <32; ++n){
        vecIntegers.push_back(n);
        cout << n << ' ' ;
    }

    int Divisor =4;
    auto iElement = find_if(vecIntegers.begin(), vecIntegers.end(), IsMultiple<int>(Divisor));
    if (iElement != vecIntegers.end()){
        cout << "\nFind the first element in vector : " ;
        cout << *iElement << endl;
    }

    return 0;
}
