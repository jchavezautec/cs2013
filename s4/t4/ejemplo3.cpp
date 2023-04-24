#include <iostream>

using namespace std;

template<class T>
struct Foo{
    Foo(){ cout << "Plantilla Original" << endl;}
};

template<>
struct Foo<int>{
    Foo(){ cout << "Plantilla Especializada" << endl;}
};

int main(){
    Foo<float> obj1;
    Foo<char> obj2;
    Foo<int> obj3;
    return 0;
}

