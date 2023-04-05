#include <iostream>

using namespace std;

class A {
public:
    void f() { cout << "A::f()" << endl; }
    void g() { cout << "A::g()" << endl; }
};
class B : public A {
public:
    void f() { cout << "B::f()" << endl; }
};
class C : public A {
public:
    void g() { cout << "C::g()" << endl; }
};

int main() {
    A a;
    B b;
    C

    a.f(); a.g();
    b.f(); b.g();

    return 0;
}