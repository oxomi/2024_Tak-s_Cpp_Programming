#include <iostream>

using namespace std;

template <typename T>
class smart_pointer{
    private:
    T* m_pRawPonter;
    public:
    smart_pointer(T* pData): m_pRawPonter(pData){}
    T& operator*() const{
        return *(m_pRawPonter);
    }

    T* operator ->()const{
        return m_pRawPonter;
    }

};

int main(){
    smart_pointer<int> pDymanicint(new int(42)); //pDynamic is "local variable" => we dont have to call delete to remove the memory space allocated in the heap

    return 0; //its destructor is automatically called
}


//key idea of Smart pointer
/*
1. A variabe in the stack -> At the end of a function body or return???
=> Automatically its destructor is called

2.
*/
