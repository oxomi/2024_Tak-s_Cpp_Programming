#include <iostream>
#include <variant>

using namespace std;

int main() {
  variant<int, double> varSafe;
  varSafe = 2.0;

  cout << "Hello world!" << endl;

  try {
    int pi = get<int>(varSafe);
  } catch(const bad_variant_access& e) {
    cout << e.what() << endl;
    cout << "Try yo access int..." << endl;
  }
  try {
    double pi = get<double>(varSafe);
  } catch(const bad_variant_access& e) {
    cout << e.what() << endl;
    cout << "Try yo access double..." << endl;
  }
  return 0;
}