#include <iostream>
using namespace std;

class President{
    public:
    static President& GetInstance(){
        static President OnlyInstance;
        return OnlyInstance;
    }

    //Getter
    string GetName(){
        return Name;
    }
    //Setter
    void SetName(string InputName){
        Name = InputName;
    }

    private:
    string Name;
    President(){};
    President(const President&); //복사생성자
    President& operator= (const President&);  //연산자 오버로딩
};

int main(){
    President& OnlyPresident = President::GetInstance();
    OnlyPresident.SetName("Abraham Lincoln");

    //생성자가 private에 있어서 접근은 안되는데 인스턴스 만드는 예시 그냥 보여주는것같음
    //President Second; // 주의: cannot access constructor
    //President* third = new President(); // 주의: cannot access constructor
    //President fourth = OnlyPresident; // copy constructor
    //OnlyPresident = President::GetInstance(); // cannot access operator assignment

    cout << President::GetInstance().GetName() << endl;

    return 0;
}