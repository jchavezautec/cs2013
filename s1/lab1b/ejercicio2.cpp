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
        precio -= km * 1;
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