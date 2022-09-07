#include <iostream>

using namespace std;

/*
void foo(auto... args);


void foo();
void foo(auto arg1);
void foo(auto arg1, auto arg2);
void foo(auto arg1, auto arg2, auto arg3, auto arg4);
*/


template<class... Ts>
void foo(Ts... args){
    cout << sizeof...(args) << endl;
}

template<class... Ts>
auto suma(Ts... args){
    return (args+...);
}

int main(){

    foo(1,2);
    foo(1,2,3,3,4,5);
    foo();

    cout << suma(1) << endl;
    cout << suma(1,2) << endl;
    cout << suma(1,2,3,4,5) << endl;

    return 0;
}