#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){

    ofstream myFile;
    myFile.open("HelloFile.txt", ios_base::out);

    //1. we need to check the file is open or not
    if (myFile.is_open()){
            cout << "File open succesful" << endl;
            myFile << "My first test file" << endl; //????? ????
            myFile << "hello File" << endl;
            myFile.close();
    }

    return 0;
}


///????????: ????? 0??1?? ??????, ???????? ????, ???? ???? ??????.
