#include <iostream>

using namespace std;

struct printString{
    char _c;
    printString(char c = ' '): _c(c) {}
    void operator() (string s){
        cout << s << _c;
    }
};


int main(){
    printString line('\n');
    line("Hola");
    
    printString excl('!');
    excl("Ingrese un entero valido");

    return 0;
}