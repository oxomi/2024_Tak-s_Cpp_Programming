#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

double Area(double R);
double Area(double R, double H);
/*
double Area(double R, int H);
double Area(int R, double H);
double Area(int R, int H);
*/

void DisplayElementFunc(int element) {
  cout << element << ' ';
}

// struct the behaves as a unary function
template<typename elementType>
struct DisplayElement {
  void operator () (const elementType element) {
    cout << element << ' ';
  }
};

// define an inline function
inline long DoubleNum(int InputNum) { // inline doesn't use STACK.
  return InputNum * 2;
}

double Area(double R) {
  return R*R*3.14;
}

double Area(double R, double H) {
  return R*R*H*3.14;
}

int main() {
  cout << "Hello world!" << endl;
  cout << Area(2.0) << endl;
  cout << Area(2, 1) << endl;
  cout << DoubleNum(4) << endl;

  int n = [](int x, int y) { return x + y; }(5, 4); // Lambda function. nameless.
  cout << n << endl;

  auto f1 = [](int x, int y) { return x + y; }; // auto is automatically assigning its type.

  // Assign the same lambda expression to a function object
  // function<int (int, int)> f2 = [](int x, int y) { return x + y; };

  int i = 3;
  int j = 5;
 
  function<int (void)> f = [i, &j] { return i + j;};
  // when you want to use the updated value, you can use reference &.
  cout << f() << endl;
  i = 22;
  j = 44;
  cout << f() << endl; // 3 + 44
  cout << f1(21, 12) << endl; // Lambda func can call another Lambda func.
  
  int m = [](int x) { return [](int y) { return y * 2; }(x) + 3;}(5);
  cout << m << endl;

  vector<int> vecIntegers;

  for (int i=0; i<10; ++i)
    vecIntegers.push_back(i);
  for_each(vecIntegers.begin(), vecIntegers.end(), DisplayElementFunc);
  cout << endl << endl;
  for_each(vecIntegers.begin(), vecIntegers.end(), DisplayElement<int>());
  cout << endl << endl;

  // Use Lambda func
  for_each(vecIntegers.begin(), vecIntegers.end(), [](int element){ cout << element << ' ';});
  cout << endl << endl;

  return 0;
}

// f()
// f: object, (): operator -> We need operator-overloading.