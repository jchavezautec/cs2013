#include <iostream>

using namespace std;

auto foo1 = [](){
    cout << "Hola Mundo" << endl;};

void foo2(){ cout << "Hola Mundo" << endl;}

struct C{
    int num = 0;
    void metodo(int x){
        auto f = []{this->num = x;};
        f();
    }
};



int main(){
    C c;
    cout << "this->num = " <<c.num << endl;
    c.metodo(5);
    cout << "this->num = " <<c.num << endl;

    return 0;
}