#include <iostream>

using namespace std;

int main() {
  /*
  int Original = 30;
  const int& ConstRef = Original; // const is read-only
  // ConstRef = 40; // so it doesn't make sense
  // int& Ref2 = ConstRef; // binding error
  const int& Ref2 = ConstRef; // NO ERROR : Type Match

  cout << "Hello world!" << endl;
  */

  int intOne = 4;
  int &rSomeRef = intOne;

  cout << intOne << endl;
  cout << rSomeRef << endl;

  cout << &intOne << endl;
  cout << &rSomeRef << endl;

  int intTwo = 8;
  rSomeRef = intTwo;

  cout << "After" << endl;

  cout << intOne << endl;
  cout << intTwo << endl;
  cout << rSomeRef << endl;

  cout << &intOne << endl;
  cout << &intTwo << endl;
  cout << &rSomeRef << endl;

  // Above works, but DO NOT REASSIGN. It's very confusing.

  return 0;
}