#include <iostream>
using namespace std;

class MonsterDB{
    private: //주의
    ~MonsterDB(){}
    
    public:
    static void DestroyInstance(MonsterDB* pInstance){ //static member can access private destructor!!!!!!!!!!
        //starting address - type:pointer-type
        delete pInstance;
    }
};


int main(){
    //MonsterDB myDatabase;
    MonsterDB* myDatabase = new MonsterDB(); //no automatic delete myDatabase!! 
    MonsterDB::DestroyInstance(myDatabase); //소멸자가 프라이빗에 있으므로 퍼블릭에서 지워주는 작업을 하는 함수 추가
    return 0;
}