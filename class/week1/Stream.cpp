#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int i = 10;

  cout << "---------------------------------" << endl;
  cout << "i: " << i << endl;
  cout << "i in octal: " << oct << i << endl;
  cout << "i in hexa: " << hex << i << endl;
  cout << "---------------------------------" << endl;
  //flag
  cout << setiosflags(ios_base::hex|ios_base::showbase|ios_base::uppercase); //iomanip 
  cout << i << endl;
  cout << resetiosflags(ios_base::hex|ios_base::showbase|ios_base::uppercase); //iomanip 
  cout << i << endl;
  cout << "---------------------------------" << endl;

  const double Pi = (double ) 22.0 / 7;
  cout << "Pi = " << Pi << endl;
  cout << setprecision(7); //정수자리 포함하여 7자리까지 나타내도록 함
  cout << "Pi = " << Pi << endl;
  cout << fixed << "Fixed Pi = " << Pi << endl;
  cout << scientific << "scientific Pi = " << Pi << endl;
  cout << "---------------------------------" << endl;
  
  // cout << setiosflags(ios_base::

  return 0;
}