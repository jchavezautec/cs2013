#include <iostream>

using namespace std;

<<<<<<< HEAD
int suma(int x1, int x2){ return x1 + x2; }
int resta(int x1, int x2){ return x1 - x2; }

void calculadora(int(*f)(int, int), int x1, int x2){
    int resultado = f(x1,x2);
    cout << resultado << endl;
}

int main(){
    int (*var_f)(int,int);

    var_f = &suma;
    calculadora(var_f, 3, 2);

    var_f = &resta;
    calculadora(var_f, 3, 2);

    return 0;
}

=======
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
>>>>>>> aaabd7447294cdb65bd133a981d5eb159087bbd9
