#include <iostream>

using namespace std;

<<<<<<< HEAD
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
=======
class printString{
private:
    char _end;
public:
    printString(char c = ' '): _end(c) {}
    void operator() (string s){
        cout << s << _end;
    }
};

#include <algorithm>

int main(){
    string v[4] = {"Hola","Mundo","en","C++"};

    for_each(v, v+4, printString('\n'));

    return 0;
}

>>>>>>> aaabd7447294cdb65bd133a981d5eb159087bbd9
