#include <iostream>
#include <cstring> //strlen, strcpy등을 쓰기 위함

using namespace std;

class MyString {
    private:
        char* Buffer;

    public:
        MyString(const char* InitialInput) {
            cout << "Constructor: creating new Mystring" << endl;
            if (InitialInput != NULL)
            {
                Buffer = new char[strlen(InitialInput) + 1];
                strcpy(Buffer, InitialInput);
                cout << "Buffer points to: " << hex;
                cout << (unsigned int *)Buffer << endl;
            }
            else{
                Buffer = NULL;
            }
        }
        
        //cpoy constructor
        MyString(const MyString& CopySource) {
            cout << "Copy constructor is called..." << endl;
            if(CopySource.Buffer != NULL){ //'copysource.buffer' mean 'sayhello.buffer'.
                Buffer = new char[strlen(CopySource.Buffer) + 1];
                strcpy(Buffer, CopySource.Buffer);
                cout << "Buffer points to: " << hex;
                cout << (unsigned int *)Buffer << endl;
            }
        }

        ~MyString() {
            cout << "Invoking destructor. clearing up" <<  endl;
            if (Buffer != NULL) 
                delete[] Buffer;
        }

        int GetLength() {
            return strlen(Buffer);
        }

        const char * GetString() {
            return Buffer;
        }
};

void useMyString(MyString Input) {
  cout << "String buffer in MyString: " << Input.GetString() << endl;
  return;
}

int main() {
  MyString SayHello("Hello from MyString Class");
  cout << "Length: " << SayHello.GetLength() << endl;
  cout << "Message: " << SayHello.GetString() << endl;
  useMyString(SayHello);

  return 0;
}


//copy constructor과 buffer에 대해서 설명하신 듯 한데 약먹으러 나가느라 못들음