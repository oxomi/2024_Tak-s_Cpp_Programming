#include <iostream>

void ReturnSquare(int& Number) {
  Number *= Number;
}

int main() {

  int Number = 20;
  ReturnSquare(Number);
  std::cout << Number << std::endl;
  
  // try {
  //   // Request lots of memory source
  //   int *pAge = new int [536870911];
  //   delete[] pAge;
  // }
  // catch (bad_alloc) {
  //   std::cout << "Memory allocation failed." << std::endl;
  // }




  // // don't kick me out of the system
  // // int* pAge = new(nothrow) int [0x1ffffffff];
  // int* pAge = new int [0x1ffffffff];

  // if (pAge) { // check pAge != NULL
  //   delete [] pAge;
  // } else {
  //   std::cout << "Memory allocation failed." << std::endl;
  // }



  // SAME THINGS
  int intOne;
  int &SomeRef = intOne;
  intOne = 5;

  std::cout << intOne << std::endl;
  std::cout << SomeRef << std::endl;
  std::cout << &intOne << std::endl;
  std::cout << &SomeRef << std::endl;

  int Original = 30;
  int& Ref = Original;

  std::cout << Original << std::endl;
  std::cout << Ref << std::endl;
  int& Ref2 = Ref;
  std::cout << Ref2 <<std::endl;

  
  std::cout << &Original << std::endl;
  std::cout << &Ref << std::endl;
  std::cout << &Ref2 <<std::endl;

  return 0;
}