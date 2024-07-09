#include <iostream>
#include <cstring>

using namespace std;

struct Human {
  Human() {}; // default construct
  Human(const char* inName, int inAge, const char* inDOB) : Age(inAge) { // member
    strcpy(Name, inName);
    strcpy(DOB, inDOB);
    // Age = inAge;
  }
  // Human(const char* inName, int inAge, const char* inDOB) {
  //   strcpy(Name, inName);
  //   strcpy(DOB, inDOB);
  //   Age = inAge;
  // }
  char Name[30];
  int Age;
  char DOB[20];
};

int main() {
  cout << "Hello World!" << endl;
  return 0;
}