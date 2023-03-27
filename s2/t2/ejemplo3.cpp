#include <iostream>

using namespace std;

class A {
public:
    virtual void f() { cout << "A::f()" << endl; }
    void g() { cout << "A::g()" << endl; }
};
class B : public A {
public:
    void f() { cout << "B::f()" << endl; }
    void g() { cout << "B::g()" << endl; }
};

int main() {
    A *a;
    B b;
    a = &b; 
    a->f(); a->g();

    return 0;
}