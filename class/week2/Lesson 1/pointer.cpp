//1 address 1 byte
//if you wanna fetch one by one, change the pointer to charactor
//

#include<iostream>
#include<string>

using namespace std;

int main(){
    int Age = 30;
    const double Pi = 3.1416;
    cout << hex << &Age << endl;
    cout << hex << &Pi << endl;

    int *pinteger = &Age;
    //&Age - the address in memory where the value (30) is placed
    cout << *pinteger << endl;
    return 0;
}
//!�����ڵ� �ּҸ� ����!������, �������� ����� �ٷ� �� �޸� ������ �ּҸ� ������.
//��, ���� ������ n�� �� �ȿ� ����� �� 10�� �ִٸ� 10�� ����� �� �޸� ������ �Ǵٸ� �̸��� �ٿ��ִ°Ͱ� ����.
//�׷��� �����ʹ� 10�� ����� �� �޸𸮰����� �ּҸ� �Ǵٸ� �޸� ������ �����ϰ� �� �Ǵٸ� �޸� ������ �����ϴ� ����. 
//s