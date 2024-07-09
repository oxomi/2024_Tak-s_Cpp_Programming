#include<iostream>

using namespace std;

class B

{
    //Implement this part
    public:
    B(){}
    virtual void show(){}

};



class D: public B

{
    
    // Implement show
    public:
    void show() override{
        cout << "In D" << endl;
    }

};



int main(void)

{

    B *b = new D;

    b->show();

    B &r = *b;

    r.show();

    return 0;


}