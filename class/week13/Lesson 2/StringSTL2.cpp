#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    cout << "Hello World!" << endl;
    string S("Helo String! Wake uo to a beautiful day!");
    transform((S.begin(), S.end(), toupper);  //교수님이 이거 고치려고 시도하셨는데 성공했나? 그건 안봄 ㅋㅋ
    cout << S << endl;
    reverse(S.begin(), S.end());
    cout << S << endl;

    string::iterator iChars = find(S.begin(), S.end(), 'S');
    auto iChars2 = find(S.begin(), S.end(), 'S');

    S.erase(13, 28);
    cout << S <<endl;
    S.erase(S.begin(), S.end());
    cout << S << endl;
    return 0;
}