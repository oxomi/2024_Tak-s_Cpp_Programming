#include <iostream>

using namespace std;

int nSum(int &n)
{
    if(n == 0) {
        n = 1;
        return 0;
    }

    n = n - 1;

    //위치에 따라서 출력값이 차이가 남
    //int res = n + nSum(n);
    int res = nSum(n) + n;

    return res;
}

int main() {
    int n = 5;

    cout << "Sum: " << nSum(n) << endl;
    
    return 0;
}