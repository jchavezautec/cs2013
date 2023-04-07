#include <iostream>

using namespace std;

template<typename... Ts>
void print(Ts... args){
    (cout << ... << args) << endl;
}

int main(){
    print();
    print(1,2,3,4,5);
    print("Hola", 1, "Mundo");

    return 0;
}
