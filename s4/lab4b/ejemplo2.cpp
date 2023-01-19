#include <iostream>

using namespace std;

template<class... Ts>
void foo(Ts... args){
    cout << sizeof...(args) << endl;
}

template<class... Ts>
auto suma(Ts... args){
    return (args+...);
}

int main(){
    cout << "Utilizando 'sizeof...'" << endl;
    foo(1,2);
    foo(1,2,3,3,4,5);
    foo();

    cout << "Utilizando 'suma'" << endl;
    cout << suma(1) << endl;
    cout << suma(1,2) << endl;
    cout << suma(1,2,3,4,5) << endl;

    return 0;
}