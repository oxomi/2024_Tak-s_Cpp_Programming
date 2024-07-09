#include <iostream>
#include <cstring> //strlen, strcpy등을 쓰기 위함

using namespace std;

class MyString {
    public:
        string Buffer;

    public:
        MyString(string InitialInput) {
            cout << "Constructor: creating new Mystring" << endl;
            Buffer = InitialInput;
            cout << "Buffer points to: " << (void *)&Buffer[0] << endl;
            
        }
        

        ~MyString() {
            cout << "Invoking destructor. clearing up" <<  endl;
        }

        //string class는 automatically 뭘 해서 1보다 뭐가 많이 필요없다

};

void useMyString(MyString Input) {
  cout << "String buffer in MyString: " << (void*)&Input.Buffer[0] << endl;
  cout << "Buffer contains " << Input.Buffer.c_str() << endl;
  return;
}

int main() {
  MyString SayHello("Hello from MyString Class");
  useMyString(SayHello);

  return 0;
}


//copy constructor과 buffer에 대해서 설명하신 듯 한데 약먹으러 나가느라 못들음