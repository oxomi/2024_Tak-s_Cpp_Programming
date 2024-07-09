#include <iostream>
#include <variant>

using namespace std;

union SimpleUnion {
  int num;
  char alphabet;
};
union SimpleUnion2 {
  int num;
  double preciseNum;
};

struct ComplexType {
  enum DataType {
    Int, Char
  } Type;
  union Value {
    int num;
    char alphabet;

    Value() {}
    ~Value() {}
  } value; // type is union Value
};

void DisplayComplexType(const ComplexType obj) {
  switch (obj.Type) {
    case ComplexType::Int: // ComplexType:: is namespace
      cout << "Union number: " << obj.value.num << endl;
      break;
    case ComplexType::Char: // ComplexType:: is namespace
      cout << "Union char: " << obj.value.alphabet << endl;
      break;
  }
}

int main() {
  cout << "Hello world!" << endl;
  SimpleUnion u1, u2;
  u1.num = 2100;
  u2.alphabet = 'C';
  cout << sizeof(u1) << endl;
  cout << sizeof(u2) << endl;

  ComplexType myData1, myData2;
  myData1.Type = ComplexType::Int;
  myData2.value.num = 2017;
  myData2.Type = ComplexType::Char;
  myData2.value.alphabet = 'X';

  DisplayComplexType(myData1);
  DisplayComplexType(myData2);

  SimpleUnion2 myU1;
  myU1.preciseNum = 3.14;
  int num2 = myU1.num;

  variant<int, double> varSafe; // this is template.
  varSafe = 3.14;

  double pi = get<double>(varSafe);
  double pi2 = get<1>(varSafe);
  // wrong examples
  // get<char>(varSafe);
  // get<2>(varSafe);

  try {
    get<int>(varSafe);
  } catch (bad_variant_access& e) {}

  return 0;
}