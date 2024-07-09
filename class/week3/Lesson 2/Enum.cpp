#include <iostream>

using namespace std;

enum ERR_CODE {SUCCESS, ERROR};

ERR_CODE Factor(int, int&, int&);

ERR_CODE Factor(int n, int&rSquared, int&rCubed) {
  rSquared = n * n;
  rCubed = n * n * n;
  return SUCCESS;
}

int main() {
  int number, squared, cubed;
  ERR_CODE result;
  number = 3;
  result = Factor(number, squared, cubed);
  cout << number << endl;
  cout << squared << endl;
  cout << cubed << endl;
  cout << result << endl;

  enum ERR_CODE {SUCCESS, ERROR};
  cout << SUCCESS << endl; 
  cout << ERROR << endl; 

  return 0;
}