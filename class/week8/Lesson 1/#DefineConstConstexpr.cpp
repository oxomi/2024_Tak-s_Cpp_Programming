//define, const, constexpr중 constexpr이 베스트.

//참고
// constexpr int max = 100;
// void use(int n)
// {
// constexpr int c1 = max + 7; // OK: c1 is 107 -> compile-time에 max란 값도 확정되어있다(constexpr)
// constexpr int c2 = n + 7; // error: we don't know the value of c2 in compile time
// const int c3 = n + 7; // OK, but don't try to change the value of c3
// const int c4; // error: const requires initializer
// c3 = 4; // error: can't change the value of const variable after initialization
//}



#include <iostream>
using namespace std;

class Foo{
    public: 
    int _i;
    constexpr explicit Foo(int i): _i{i}{}
    constexpr int GetValue() const{
        return _i;
    }
};

constexpr double GetPI(){return 22.0 / 7;}

constexpr int myaddition(int i, int j){
    return i+j;
}
constexpr int myconstaddition(int i, int j){
    return i+j;
}

//compile-time computatuion of array length
template <typename T, int N>  
constexpr int length(const T(&)[N]) {
  return N;
}

int main(){
    //foo is const
    constexpr Foo foo(5);

    const int nums[] {1,2,3,4};
    const int nums2[length(nums) * 2] {1,2,3,4,5,6,7,8};

    cout << GetPI() << endl;

    // int age;
    // cin >> age;
    // // const int userAge = age;
    // const int userAge(age);
    // // constexpr int userAge = age; error
    // cout << userAge; 
    // //actually,userage will be decide at RunTime

    constexpr float y(108);
    //const int j;  error
    //constexpr int j; error
    int j = 0; 
    int k = 10;
    // constexpr int k = j + 1 ;
    j = myaddition(10, 10);
    j = myaddition(k, k);

    j = myconstaddition(10, 10);
    j = myconstaddition(k, k);

    const int m = myconstaddition(10, 10);
    const int n = myconstaddition(k, k);

    constexpr int x = myaddition(10, 10);
    cout << foo.GetValue() << endl;
    cout << length(nums) << endl;

    return 0;
}


//you can create an instance from stack or heap.
//instance are prohibited on stak.
// - size is limited