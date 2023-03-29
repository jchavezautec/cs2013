/*
Ejercicio:

Implemente un programa en C++ con los siguientes requisitos:

1. Crear una clase llamada Auto
2. La clase Auto debe tener los siguientes atributos:
    - color
    - precio
    - kilometraje (inicializado en 0)
2. Crear el metodo viajar() que recibe como parametro la cantidad de kilometros a recorrer
   y actualice el atributo kilometraje. El metodo debe imprimir un mensaje indicando la cantidad
   de kilometros recorridos hasta el momento.
3. Utilizar encapsulamiento para los atributos de la clase Auto.
4. Crear un constructor que reciba como parametros el color y el precio del auto.
5. Crear un constructor copia para la clase Auto.
6. Crear una funcion amiga mostrar() que reciba como parametro un objeto de la clase Auto y
   muestre por pantalla los atributos del auto.
*/

#include <iostream>

using namespace std;

class Auto{
private:
    string color;
    int precio;
    int kilometraje;

public:
    Auto(string color, int precio){
        this->color = color;
        this->precio = precio;
        this->kilometraje = 0;
    }

    Auto(const Auto &a){
        this->color = a.color;
        this->precio = a.precio;
        this->kilometraje = a.kilometraje;
    }

    void viajar(int km){
        kilometraje += km;
        cout << "Kilometros recorridos: " << kilometraje << endl;
    }

    friend void mostrar(Auto a);
};

void mostrar(Auto a){
    cout << "Color: " << a.color << endl;
    cout << "Precio: " << a.precio << endl;
    cout << "Kilometraje: " << a.kilometraje << endl;
}

int main(){
    Auto a1("Rojo", 100000);
    Auto a2 = a1;

    a1.viajar(100);
    a2.viajar(200);

    mostrar(a1);
    mostrar(a2);

    return 0;
}