#include <iostream>
#include <string>

using namespace std;

class Human {
public:
  int Age;
  string Name;
  string DateOfBirth;
public:
  Human() {
    Age = 10;
    cout << "Constructor is called!!" << endl;
  }
  ~Human() { // Destructor
    cout << "Destructor is called!!" << endl;
  }
  void Talk(string TextToTalk) {
    cout << TextToTalk << endl;
  }
  void Introduce() {
    cout << "Age: " << Age << endl;
    cout << "Name: " << Name << endl;
    cout << "DateOfBirth: " << DateOfBirth << endl;
  }
};

int main() {
  // INSTANCE -> located in STACK
  Human Julie;

  Julie.Age = 21;
  Julie.Name = "Julie Anna";
  Julie.Introduce();

  Human *Joe = new Human();
  (*Joe).Age = 23;
  (*Joe).Name = "Joe";
  (*Joe).Introduce();
  Joe -> Introduce(); // -> operator represents Introcduce.

  cout << "hello world!" << endl;
  return 0;
}