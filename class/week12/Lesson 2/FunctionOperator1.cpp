#include <iostream>

using namespace std;

class C{
    public:
    void operator() (string Input) const{
        cout << Input << endl;
    }

};

int main(){
    C myC;
    myC("Test");

    return 0;
}