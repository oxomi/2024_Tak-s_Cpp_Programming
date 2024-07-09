#include <iostream>

using namespace std;

class Simple {
public:
  int i = 10;
  int j = 20;

  void Setl(int i) {
    // i = i; // i is local variable. local variable has top priority.
    this->i = i; // this 쓸 때마다 starting 주소?가 업데이트 됨
    this->j = i;
    this->Setl(11);
    // j = i; // j is member variable.
  }
};

int main() {
  Simple S;

  S.Setl(11);
  cout << S.i << endl;

  return 0;
}
