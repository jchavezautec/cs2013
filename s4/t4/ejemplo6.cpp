#include <iostream>

using namespace std;

void print(){cout << endl;}

template<typename T, typename... Ts>
void print(T arg, Ts... args){
    cout << arg;
    print(args...);
}

int main(){
    print();
    print(1,2,3,4,5);
    print("Hola", 1, "Mundo");

    return 0;
}
