#include <iostream>

using namespace std;

class Foo{
    public:
        static int x;
};

int Foo::x = 3;

int main(){
    Foo obj1;
    cout << obj1.x << endl;
    
    Foo obj2;
    cout << obj2.x << endl;

    return 0;
}