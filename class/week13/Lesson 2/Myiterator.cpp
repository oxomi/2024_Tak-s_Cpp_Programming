#include <stdio.h>

typedef int Type;

struct IType { // template, iterator
  Type* p; // data가 아닌 *data를 사용하고 싶다면 포인터를 선언해줘야 함
  IType(Type *_p): p(_p) {} // constructor
  bool operator != (IType rhs) {
    return p != rhs.p;
  }
  Type& operator* () {
    return *p;
  }
  void operator++ () {
    ++p;
  }
};

const int SIZE = 10;
struct Iterable {
  Type data[SIZE];
  IType begin() { return IType(data); } // IType(data) requires IType
  IType end() { return IType(data+SIZE); } // begin + length = end
};

using namespace std;

Iterable iterable;
int main() {
  int i = 0;
  for (Type& x: iterable) {
    x = i++;
  }
  for (Type& x: iterable) {
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}

//엥 오류뜨는데 컴파일은 되노
//일단 그대로 따라친건 맞음
