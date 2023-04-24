#include <iostream>

using namespace std;

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

