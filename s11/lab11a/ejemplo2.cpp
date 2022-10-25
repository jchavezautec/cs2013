#include <iostream>

using namespace std;

class Foo{
    public:
        static int x;
        int y;

        static void f1(){
            x = 2;
            y = 3;
        } 
        void f2(){
            x = 2;
            y = 3;
        }
};

int Foo::x = 3;

int main(){
    Foo obj1;
    cout << obj1.x << endl;
    
    Foo obj2;
    cout << obj2.x << endl;

    return 0;
}