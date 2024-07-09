#include <iostream>
#include <map>
#include <string>
#include <algorithm>


using namespace std;


typedef map<int, string> MAP_INT_STRING;
typedef multimap<int, string> MMAP_INT_STRING;
typedef map<string, string> DIRECTORY_NOCASE;
typedef map<string, string> DIRECTORY_WITHCASE;

template <typename T>
void DisplayContents(const T& Input){
    for(auto iE = Input.cbegin(); iE != Input.cend(); ++iE){
        cout << iE->first << "->" << iE->second << endl;
    }
    cout << endl;
}

struct PredcateIgnoreCase{  //대소문자 구분 없는 비교
    bool operator()(const string& str1, const string& str2) const{
        string str1NoCase(str1), str2NoCase(str2);
        transform(str1.begin(), str1.end(), str1NoCase.begin(), (int(*)(int))tolower); //tolower은 왜 이렇게 해줘야 하는거노?
    }
};

void output(const auto& table){
    for(auto const& [key, value] : table){
        cout << key << "->" << value << endl;  
    }
    cout << endl;
}


int main(){
    MAP_INT_STRING mapIntToString;

    //using value_type
    mapIntToString.insert(MAP_INT_STRING::value_type(3, "Three"));
    //using function make_pair
    mapIntToString.insert(make_pair(-1, "Minus One"));
    //using a pair object directly
    mapIntToString.insert(pair<int, string>(1000, "One Thousand"));
    //using an array style
    mapIntToString[1000000] = "One Million";
    cout << "Size: " << mapIntToString.size() << endl;


    //1st approach
    DisplayContents(mapIntToString);

    //2nd approach
    map<int, string>::iterator it;
    for(it = mapIntToString.begin(); it != mapIntToString.end(); it++){
        cout << it->first << "->" << it->second << endl;
    }
    cout << endl;

    //3rd approach c++11 version
    for(auto const& x : mapIntToString){
        cout << x.first << "->" << x.second << endl;  //x는 포인터변수가 아니므로 ->가 아니라 .을 써줘야 한다.
    }
    cout << endl;

    //4th appreach c++17 verion
    for(auto const& [key, value] : mapIntToString){
        cout << key << "->" << value << endl;  
    }
    cout << endl;

    //5th appreach c++11 version
    for(const auto& x : mapIntToString){
        cout << x.first << "->" << x.second << endl;  
    }
    cout << endl;    

    //6th appreach
    for(auto it = mapIntToString.begin(); it != mapIntToString.end(); it++){
        cout << it->first << "->" << it->second << endl;
    }
    cout << endl;

    //7th approach
    output(mapIntToString);


    MMAP_INT_STRING mmpaIntToString(mapIntToString.cbegin(), mapIntToString.cend());
    mmpaIntToString.insert(make_pair(1000, "Thousand"));
    DisplayContents(mmpaIntToString);
    cout << "Then number 1000: " << mmpaIntToString.count(1000) << endl;


    int key = 1000;
    auto iPairFound = mapIntToString.find(key);
    if (iPairFound != mapIntToString.end()){
        cout << "key: " << iPairFound->first << "->" << iPairFound->second << endl;
    }
    else{
        cout << "Sorry, pait with key" << key << "not in the map" << endl;
    }

    DIRECTORY_NOCASE dirCaseInensitive;

    dirCaseInensitive.insert(make_pair("John", "2345674"));
    dirCaseInensitive.insert(make_pair("JOHN", "2345674"));
    dirCaseInensitive.insert(make_pair("Sara", "2345674"));
    dirCaseInensitive.insert(make_pair("Jack", "2345674"));

    DisplayContents(dirCaseInensitive);

    DIRECTORY_WITHCASE dirCaseSensitive(dirCaseInensitive.begin(), dirCaseInensitive.end());
    DisplayContents(dirCaseSensitive);

    string strNameInput = "Sara";
    auto iPairInNOcaseDir = dirCaseInensitive.find(strNameInput);
    if(iPairInNOcaseDir != dirCaseInensitive.end()){
        cout << iPairInNOcaseDir->first << "->" << iPairInNOcaseDir->second << " found!!" << endl;
    }
    else{
        cout << strNameInput << " is not found" << endl;
    }

    auto iPairInCaseSensDir = dirCaseSensitive.find(strNameInput);

    if(iPairInCaseSensDir != dirCaseSensitive.end()){
        cout << iPairInCaseSensDir->first << "->" <<  //이부분 수정 필요
    }

    return 0;
}