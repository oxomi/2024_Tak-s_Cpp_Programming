//리스트와 벡터 입출력구조 복습
//23 리스트 피피티
//STL set classes - a set, multiset

#include <iostream>
#include <list>
#include <string>
#include <forward_list>
#include <set> //do not modify the element value in the set..? ->< find, erase, insert

using namespace std;

struct ContactItem
{
    int k;
    string Name;
    string PhoneNumber;
    string Representation;

    ContactItem(const string& strName, const string& strNumber){
        Name = strName;
        PhoneNumber = strNumber;
        Representation = (Name + ": " + PhoneNumber);
    }

    //used by list.remove() given contact list item
    bool operator == (const ContactItem& itemToCompare) const {
        //int i = 0;
        // i = 10;
        // k = 10; //왜 오류뜨는지 설명하셨는데 왠지 모르겠 ㅋㅋ
        return (itemToCompare.Name == this->Name);
    }

    //used by list.sort()
    bool operator < (const ContactItem& itemToCompare) const{
        return (this->Name < itemToCompare.Name);
    }

    operator const char *() const{
        return Representation.c_str();
    }
};

bool SortPredicate_Descending(const int& lsh, const int& rsh){
    return (lsh > rsh);
}


template <typename T>
void DisplayContents(const T& input){
    for (auto iElement = input.cbegin(); iElement != input.cend(); ++iElement){
        cout << *iElement << endl;
    }
    cout << endl;
}


int main(){
    list<int> listintegers;

    listintegers.push_front(4);
    listintegers.push_front(3);
    listintegers.push_front(2);
    listintegers.push_front(1);
    listintegers.push_front(0);
    listintegers.push_back(5);

    listintegers.insert(listintegers.begin(), 2);
    listintegers.insert(listintegers.end(), 100);
    for(int& x: listintegers) cout << x << endl;

    listintegers.reverse();
    for(int& x: listintegers) cout << x << endl;



    list<int> myList;
    myList.push_front(444);
    myList.push_front(2024);
    myList.push_front(-1);
    myList.push_front(0);
    myList.push_front(-5);
    myList.sort();  //sort 함수의 구조에 대해서 설명하심
    for (int& x : myList) cout << x << endl;
    cout << endl; 
    myList.sort(SortPredicate_Descending);
    for (int& x : myList) cout << x << endl;

    list<ContactItem> myContacts;
    myContacts.push_back(ContactItem("Trumph", "555"));
    myContacts.push_back(ContactItem("Biden", "444"));
    myContacts.push_back(ContactItem("Zico", "333"));
    myContacts.push_back(ContactItem("Lesseraphim", "222"));
    myContacts.push_back(ContactItem("Aespa", "111"));
    myContacts.sort();
    DisplayContents(myContacts);
    cout << endl;
    for(ContactItem& x : myContacts){
        cout << x.Representation << endl;
    }
    cout << endl;

    myContacts.remove(ContactItem("Trumph", " ")); //숫자필요없대. 왜여?
    DisplayContents(myContacts);
    
    forward_list<int> fListintegers;
    fListintegers.push_front(0);
    //fListintegers.push_back(0); //에러가 발생함.

    set<int> setintegers;
    multiset<int> msetintegers;

    setintegers.insert(80);
    setintegers.insert(-1);
    setintegers.insert(3000);
    setintegers.insert(3000); //얘를 해도 3000은 하나만 뜬다.
    cout << endl;
    for(const int& x : setintegers){
        cout << x << " ";
    }
    cout << endl;


    msetintegers.insert(setintegers.begin(), setintegers.end());
    msetintegers.insert(3000); //이렇게 하면 3000이 두개 뜬다
    cout << endl;
    for (const int& x : msetintegers){  
        //x = 2000; //we cannnot modified valuer set..?
        cout << x << " ";
    }
    cout << endl;


    //i want to change element values in the set
    int x = 10;
    const int* y = &x;
    int *z;

    //*y = 11; //OK or Bad => Bad. Because of const
    //z = y;
    z = const_cast<int*>(y);  //OK!
    *z = 12;
    cout << "z: " << *z << "  y: " << *y << endl;

    
    set<int> mySet;
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(2);

    // int j = 10;
    // for (auto i = mySet.begin(); i != mySet.end(); i++){
    //     int* elem = const_cast<int*>(&*i);
    //     *elem = j--;
    // }

    // for(const int& x : mySet){
    //     cout << x <<endl;
    // }

    return 0;
}