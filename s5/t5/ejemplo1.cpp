#include <iostream>

using namespace std;

<<<<<<< HEAD
void printer(){
    cout << "Hola Mundo" << endl;
}

int suma(int x1, int x2){ return x1 + x2; }
int resta(int x1, int x2){ return x1 - x2; }

void calculadora(int(*f)(int, int), int x1, int x2){
    int resultado = f(x1,x2);
    cout << resultado << endl;
}

int main(){
    calculadora(&suma, 3, 2);
    calculadora(&resta, 3, 2);

    return 0;
}

=======
int suma(int x1, int x2){return x1 + x2;}
int resta(int x1, int x2){return x1 - x2;}

void calculadora(int (*f)(int, int), int x1, int x2){
    cout << "El resultado es: " << f(x1, x2) << endl;
}

int main(){
    int x1, x2;
    cout << "Introduzca dos numeros: ";
    cin >> x1 >> x2;
    calculadora(suma, x1, x2);
    calculadora(resta, x1, x2);

    int (*pf)(int, int);

    pf = suma;
    cout << "El resultado es: " << pf(x1, x2) << endl;
    pf = resta;
    cout << "El resultado es: " << pf(x1, x2) << endl;
    return 0;
}
>>>>>>> aaabd7447294cdb65bd133a981d5eb159087bbd9
