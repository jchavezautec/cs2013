#include <iostream>
#include <vector>
using namespace std;

class Foo{
public:
    Foo(int x){ ptr = new int(x);}
    Foo(const Foo& item): ptr(item.ptr){
        cout << "Constructor de Copia" << endl;
    }
    Foo(Foo&& item): ptr(item.ptr){
        item.ptr = NULL;
        cout << "Constructor de Movimiento" << endl;
    }
    void print(){cout << *ptr << endl;}
    ~Foo(){
        delete ptr;
        ptr=NULL;
    }
private:
    int* ptr;
};

int main(){
    Foo p1(1);
    Foo p2 = p1;
    p2.print();
    p1.print();

    Foo p3 = move(p1);
    p3.print();
    p1.print();
}