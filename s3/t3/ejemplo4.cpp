#include <iostream>

using namespace std;

template<int n>
struct A{
    int area = n * n;
};

template<int n = 3>
struct B{
    int area = n * 3;
};

template<auto k> // C++17
struct C{};

int main(){
    A<5> a1;
    cout << a1.area << endl; // Resultado: 25
    B b1;
    cout << b1.area << endl; // Resultado: 9
    C<'a'> c1;
}