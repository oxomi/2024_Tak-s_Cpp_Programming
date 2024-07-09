#include <iostream>

using namespace std;

//we want to display integer and double (floating point)
template<typename T>
void DisplayData(const T& data){
    if constexpr(is_integral<T>::value)
        cout << "Integral data: " << data << endl;
    else if constexpr(is_floating_point<T> :: value)
        cout << "Floating point data: " << data << endl;
    else
        cout << "Unindeitied data: " << data << endl;
}

int main(){
    DisplayData(12);
    DisplayData("Hello");
    return 0;
}