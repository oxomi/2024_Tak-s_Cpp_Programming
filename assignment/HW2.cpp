#include <iostream>
using namespace std;
int main ()
{
    int numbers[10];
    int * p;
    for (int n=0; n<10; n++)
    cout << numbers[n] << ", ";
    p = numbers; *p = 10;
    p++; *p = 20;
    p = &numbers[2]; *p = 30;
    p = numbers + 3; *p = 40;
    p = numbers; *(p+4) = 50;
    cout << *p++ << endl; // same as *(p++): increment pointer, and dereference unincremented address
    cout << *++p << endl; // same as *(++p): increment pointer, and dereference incremented address
    cout << ++*p << endl; // same as ++(*p): dereference pointer, and increment the value it points to
    cout << (*p)++ << endl; // dereference pointer, and post-increment the value it
    for (int n=0; n<10; n++)
    cout << numbers[n] << ", ";
    return 0;
}