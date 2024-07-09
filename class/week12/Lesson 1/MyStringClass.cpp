//this가 제일 어려움
//공부 제일 많이 해야하는 부분일듯.
//this가 return될때도 있고 막 void가 return 될때도 있고 그런가봄


#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* Buffer;  //배열의 첫주소를 저장할 변수. 문자열 데이터를 저장하는 동적 배열

public:
    MyString(const char* InitialInput) {  //생성자 : 배열의 초기 포인터(주소) 를 인자로 받음
        cout << "Constructor: creating new MyString " << endl;
        if (InitialInput != NULL) {
            Buffer = new char[strlen(InitialInput) + 1];
            
            strcpy(Buffer, InitialInput);
            cout << "Buffer points to: " << hex;
            cout << (unsigned int*)Buffer << endl;
        }
        else
            Buffer = NULL;
    }

    // Copy Constructor
    MyString(const MyString& CopySource) {
        cout << "Copy Constructor is called ..." << endl;
        if (CopySource.Buffer != NULL) {
            Buffer = new char [strlen(CopySource.Buffer) + 1];
            strcpy(Buffer, CopySource.Buffer);
            cout << "Buffer points to: " << hex;
            cout << (unsigned int*)Buffer << endl;
        }

    }

    ~MyString() {
        cout << "Invoking destructor,  clearing up" << endl;
        if (Buffer != NULL)
            delete [] Buffer;
    }
    
    
    int GetLength() {
        return strlen(Buffer);
    }
    const char * GetString() {
        return Buffer;
    }


    //!!
    operator const char*(){ 
        return Buffer;
    }

    //중요한듯
    MyString& operator= (MyString& CopySource) {//string2 = string1 : main이 string1이 copysource에 들어감. string2는 this가됨
        cout << "operator= is called" <<endl;
        if((this != &CopySource)&&(CopySource.Buffer != NULL)){
            if(Buffer != NULL){
                delete[] Buffer;
            }
            Buffer = new char[strlen(CopySource.Buffer)+1];
            strcpy(Buffer, CopySource.Buffer);
        }
        return *this;
    }
    
    const char& operator[](int index) const{
        cout << "operator [] is testing..." << endl;
        return Buffer[index];
    }



};

//this와 버퍼의 관계
void useMyString(MyString Input) {
    cout << "String buffer in MyString: " << Input.GetString() << endl;
    return;
}

int main()
{

    MyString SayHello("Hello from MyString Class");
    cout << "Length: " << SayHello.GetLength() << endl;
    cout << "Message: " << SayHello.GetString() << endl;
    useMyString(SayHello);

    MyString String1("Hello ");
    MyString String2("World!");

    cout << String1 << String2 << endl;  //!!에 있는 코드를 추가하니 정상작동

    String2 = String1;

    cout << String1 << String2 << endl;

    cout << String1[1] << endl;  //next class에서 본다고 함 근데 넥스트클래스를 제대로안들었노띠앙
    return 0;;
}

//킬킬 제대로 못들음