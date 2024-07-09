#include <iostream>

using namespace std;

int main() {
  int Age = 30;
  int DogAge = 0; // Automatically allocated in the memory by the C++ Compiler
  // Pointer type variable must access to some variable alive in the memory
  int* pInteger = &Age;
  cout << pInteger << endl; // Age의 주솟값을 프린트

  pInteger = &DogAge;
  cout << pInteger << endl; // DogAge의 주솟값을 프린트
  cout << sizeof(pInteger) << endl;

  char* pChar;
  *pChar = 'A';
  cout << *pChar << endl;
  cout << sizeof(pChar) << endl;
  // 첫 시작 주소를 알면, 전체 사이즈를 알 수 있음 size of stack?
  
  // int* pNumbers = new int; // Heap: dynamic allocation, new -> pointer

  // every function has its own STACK!!
  // use HEAP not stack!

  // delete [] pNumbers;
  // int* myP = new int(4);
  //*myP;

  int* pNumbers = new int(10);
  for (int i=0; i<10; i++) {
    cout << *(pNumbers + i) << endl;
    cout << pNumbers[i] << endl;
  }
  return 0;
}


//int* -> starting address and how many 를 담고 있다.
//new : allocate memorys. where? -> heap(Dynamic allocation)

//heap can be shared by other function.
//we must manage the heap ourself, but stack don't have to. 
//stack manage memory automatically