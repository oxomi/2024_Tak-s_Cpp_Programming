#include<iostream>

#include<vector>

using namespace std;



// template function to perform sort on array, arr

// n: size of arr

template<typename T>

void MySort(T arr[], int n)

{
    vector<T> arr1(arr, arr + n); 
    //배열을 벡터에 복사하는 방법. arr을 그냥 배열로 놔둘랬는데 그러면 arr의 요소를 삭제하는게 안돼서 일단 벡터로 만들어 봄.
    
    T *arr2 = new T[n];
    //arr2를  그냥 배열로 만든 이유는 밑에 delete[]를 해줘야 한다길래. 벡터는 자동으로 메모리 관리를 해주므로 그럴 필요 없으니까..


    for (int i=0; i < n; i++){
        T min = arr1[0];
        int minindex = 0;

        for (int j = 1; j < arr1.size(); j++){ //min 찾는 로직
            if(min > arr1[j]){
                min = arr1[j];
                minindex = j;
            }
        }

        arr2[i] = min;
        arr1.erase(arr1.begin() + minindex);
    }

    for (int k = 0; k < n; k++){
        arr[k] = arr2[k];
    }

    delete[] arr2;

    /* Implement this part!!

    create a new arr2[] from the heap;

    copy arr[] into arr2[];

    int i = 0;

    loop(some sonditions) {

        Find the min from arr[];

        insert the min into arr2[i];

        Remove the min from arr[];

        i++; 

     } 

     copy arr2[] into arr[];

     delete [] arr2;

     */

}



// Template function to print array

// n: size of arr[]

template<typename T>

void PrintArray(T arr[], int n)

{

    for (int i = 0; i < n; ++i)

        cout << arr[i] << " ";

    cout << "\n";

}



int main()

{



    int arr[] = { 1, 10, 90, 100, -1, 11, 9, 14, 3, 2, 20, 19 };

    int n = sizeof(arr) / sizeof(int);

    MySort(arr, n);

    PrintArray(arr, n);



    char arr2[] = { 'c', 'x', 'a', 't', 'r', 'z' };

    n = sizeof(arr2) / sizeof(char);

    MySort(arr2, n);

    PrintArray(arr2, n);



    double arr3[] = { -1000.3, -1, 100.3, 100.1, 1000, -200 };

    n = sizeof(arr3) / sizeof(double);

    MySort(arr3, n);

    PrintArray(arr3, n);

}