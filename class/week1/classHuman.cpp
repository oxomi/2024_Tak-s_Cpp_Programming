#include <iostream>
#include <string>

using namespace std;

class Human {
private:
  string Name = "Tom cruise";
  int Age = 23;
public:
  int GetAge() {
    return Age;
  }
  void SetAge (int HumanAge) {
    Age = HumanAge;
  }
};

int main() {
  Human Tom;
  Tom.SetAge(24);
  cout << Tom.GetAge() << endl;

  return 0;
}