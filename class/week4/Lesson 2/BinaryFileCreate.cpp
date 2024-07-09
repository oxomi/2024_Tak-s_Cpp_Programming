#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <vector> //array = vector


using namespace std;

struct Human {
    Human() {};
    Human(const char* inName, int inAge, const char* inDOB) : Age(inAge) { //축약한 형태
        strcpy(Name, inName);
        strcpy(DOB, inDOB);
        //Age = inAge;
    }
    /*
    Human(const char* inName, int inAge, const char* inDOB) {
        strcpy(Name, inName);
        strcpy(DOB, inDOB);
        Age = inAge;
    }
    */
    char Name[30];
    int Age;
    char DOB[20];

};
int main()
{
    cout << "Hello world!" << endl;
    Human Input("Tom Cruise", 101, "May 1910");
    ofstream fsOut("MyBinary.bin", ios_base::out | ios_base::binary);

    if(fsOut.is_open()){
        cout << "Writing..." << endl;
        // fsOut.write((const char*)(&Input), sizeof(Input));  //<C-style Type Cast>
        // Human is object class (typecast) Input is Human class, "write" require const char pointer 
        // object class is not pointer, then we have to give address (using '&' operator)
        fsOut.write(reinterpret_cast<const char*>(&Input), sizeof(Input));   //C++-style Type Cast
        fsOut.close();
    }

    ifstream fsIn("MyBinary.bin", ios_base::in | ios_base::binary);
    if(fsIn.is_open()){
        Human somePerson;
        fsIn.read((char *)&somePerson, sizeof(somePerson));
        cout << "Name: " << somePerson.Name <<endl;;
        cout << "Age: " << somePerson.Age << endl;
        cout << "DOB: " << somePerson.DOB << endl;

    //(void *)(     )
    // 파일에 abs1910 이런식으로 일렬로 되어있르면 우리는 이러한 데이터를 읽어들여야한다.
    // 그러나 컴퓨터의 뷰로는 이런 데이터릐 타입을 정의할 수 없다
    // 컴파일러가 타입캐스트를 수행해서 Human의 타입으로 변환해줌..? 타입캐스트가 아직 뭔지 모르겠다
    }   

    //sstream 추가
    int i=10;
    stringstream convertStream;
    convertStream << i; //i를 string으로 convert!
    string strInput;
    convertStream >> strInput; //convert한 것을 strInput에 저장
    cout << i << endl;
    cout << strInput << endl;

    int MyNumbers[] = {2011, 2052, -525}; //배열의 개수를 알 수 있도록 해야함.
    int Solar[2][3] = {{0, 1, 2}, {3, 4, 5}};

    vector<int> DynArr(3); //vector is Dynamic array >>Class<<
    DynArr[0] = 3365;
    DynArr[1] = -421;
    DynArr[2] = 789;

    cout << "Size: " << DynArr.size() << endl;
    int AnotherNum = 400;
    DynArr.push_back(AnotherNum);
    cout << "Size: " << DynArr.size() << endl;

    char SayHello[] = {'H', 'e', 'l', 'l', 'o',' ', 'W', '\0'};
    cout << SayHello << endl;
    cout << sizeof(SayHello) << endl; //output : 8

    SayHello[5] = '\0'; 
    cout << SayHello << endl; 
    cout << sizeof(SayHello) << endl;
    //인덱스 5에 배열의 끝을 의미하는 널문자를 넣었기때문에 hello만 프린트 된다.
    //그러나 주의할 것은 사이즈는 여전히 8!

    // string MyString = "Hello\0W"; //string class에서 연산자 오버로딩으로 =를 대입으로 지정하였기 떄문에 이렇게 쓸 수 있는 것
    string MyString("Hello\0W"); //string is class! ex)constructor - string(const char*)
    cout << MyString << endl;
    string SeeString = "Ha Ha";
    string ConCat = MyString + SeeString; //string class의 연산자 오버로딩
    cout << ConCat << endl;

    return 0;
}


