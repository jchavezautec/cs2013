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
    B b1;
    C<'a'> c1;
}