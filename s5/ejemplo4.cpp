#include <iostream>

using namespace std;

class printString{
private:
    char _end;
public:
    printString(char c = ' '): _end(c) {}
    void operator() (string s){
        cout << s << _end;
    }
};
int main(){
    printString line('\n');
    line("Hola");
    
    printString excl('!');
    excl("Ingrese un entero valido");

    return 0;
}