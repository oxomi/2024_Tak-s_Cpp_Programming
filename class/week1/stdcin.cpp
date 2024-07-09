#include <iostream>

using namespace std;

int main() {
  int inputNumber;
  string inputName;

  cout << "HelloWorld!" << endl;

  cout << "Input an Integer: ";
  cin >> inputNumber;

  cout << "Input a Name: ";
  cin >> inputName; //공백 기준으로 앞에 있는 것 출력

  cout << "The Number: " << inputNumber << endl;
  cout << "The Name: " << inputName << endl;

  return 0;
}