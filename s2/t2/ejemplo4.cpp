#include <iostream>

using namespace std;

class A{
public:
    int f(int x) { return x;} 
    int f(int x, int y) { return x + y;}
};

class B{
public:
    virtual void f() { cout << "B::f()"<<endl;}
};
 
class D: public B{
    public:
    void f() { cout << "D::f()"<<endl;}
};
 
int main(){
    A a;
    cout << "f:" << a.f(2) << endl;
    cout << "f:" << a.f(2,3) << endl;
 
    B b;
    D d;
 
    B *bPtr = &b;
    bPtr->f();
 
    bPtr = &d;
    bPtr->f();
 
    return 0;
}