// PPT 13
#include <iostream>

using namespace std;

class FishDummyMember {
public:
  FishDummyMember() {
    cout << "FishDummyMember constructor" << endl;
  }
  ~FishDummyMember() {
    cout << "FishDummyMember destructor" << endl;
  }
};

class Fish {
protected:
  FishDummyMember dummy;
public:
  Fish() {
    cout << "Fish constructor" << endl;
  }
  ~Fish() {
    cout << "Fish destructor" << endl;
  }
};

int main() {
  Fish myFish; // local variable
  return 0; // remove the main()'s stack (local variable)
}

// Fish has a "FishDummyMember"
// - To Construct a Fish, we first create "FishDummyMember"
// - To Destruct a Fish, we first destruct "FishDummyMember"