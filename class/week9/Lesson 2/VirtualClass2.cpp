#include <iostream>

using namespace std;

class Parent {
public:
  void show() { cout << "This is Parent." << endl; }
  /*
  void show(int a) {
    cout << "a: " << a << endl;
  }
  */
  virtual void show2() { cout << "This is Parent show2." << endl; }
  virtual void show3() { cout << "This is Parent show3." << endl; }
  virtual void show4() { cout << "This is Parent show4." << endl; }
};

class Child: public Parent {
public:
  virtual void show() { cout << "This is Child." << endl; }
  virtual void show2() { cout << "This is Child2." << endl; }
};

class ChildChild: public Child {
public:
  virtual void show() { cout << "This is ChildChild." << endl; }
};

int main() {
  Parent *p = new Parent;
  Child *c = new Child;
  ChildChild *cc = new ChildChild;

  // Below ones Static Binding at Compile time. cf) dynamic binding -> run-time
  // p->show(); c->show(); cc->show(); // STEP 1
  // OVERRIDING
  // While compiler is parsing the building, Function Binding will happen.

  /*
  p = c;
  p->show();
  p = cc;
  p->show();
  */

  /*
  c->show();
  c->show(10); // error. integer hidden
  */

  p->show();
  c->show();
  c->show3();
  c->show4();
  cc->show3();
  cc->show();
  cc->show2();

  return 0;
}