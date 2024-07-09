#include <iostream>

using namespace std;

int main()
{
  int Age = 30;
  int *pInteger = &Age; // pointer to an int, initialzed to &Age
  
  // Displaying the value of pointer
  cout << "Ingeter Age is at: " << hex << pInteger << endl;
  return 0;
}