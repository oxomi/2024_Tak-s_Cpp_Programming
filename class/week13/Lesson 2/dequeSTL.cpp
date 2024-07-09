//deque - vector의 단점을 보완하기 위해서 만들어진 container
// vector는 새로운 원소가 추가 될때 메모리 재할당 후 이전 원소를 복사하는 방식으로 인하여, 
// 삽입시에 성능이 저하되는 단점이 있습니다.
// deque는 이러한 vector의 단점을 보완하기 위해서 여러개의 메모리 블록을 할당하고
// 하나의 블록처럼 여기는 기능을 제공합니다.
// deque는 메모리가 부족할때 마다 일정한 크기의 새로운 메모리 블록을 할당합니다. 
// 그럼으로써, 이전 원소를 복사하지 않습니다.


//피피티 22

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    deque<int> dequeIntegers;
    dequeIntegers.push_back(3);
    dequeIntegers.push_back(4);
    dequeIntegers.push_back(5);

    dequeIntegers.push_front(2);
    dequeIntegers.push_front(1);
    dequeIntegers.push_front(0);



    for(size_t i = 0; i < dequeIntegers.size(); ++i){
        cout << "E[" << i << "]=";
        cout << dequeIntegers[i] << endl;
    }

    cout <<endl;

    dequeIntegers.pop_front();
    dequeIntegers.pop_back();
    cout << endl;
    for(size_t i = 0; i < dequeIntegers.size(); ++i){
        cout << "E[" << i << "]=";
        cout << dequeIntegers[i] << endl;
    }

    cout << endl;

    for(auto iE = dequeIntegers.begin(); iE != dequeIntegers.end(); ++iE){
        size_t offset = distance(dequeIntegers.begin(), iE);
        cout << "E[" << offset << "]=";
        cout << dequeIntegers[offset] << endl;
    }


    for (int& x: dequeIntegers){  //for(Type& x : iterable) 테크닉
        cout << x << endl;
    }
    return 0;
}