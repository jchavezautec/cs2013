#include <iostream>

using namespace std;

template<class T>
class Foo{
    public:
        Foo(){
            cout << "Plantilla Original" << endl;
        }
};

template<>
class Foo<int>{
    public:
        Foo(){
            cout << "Plantilla Especializada" << endl;
        }
};

int main(){
    Foo<float> obj1;
    Foo<char> obj2;
    Foo<int> obj3;

    return 0;
}

