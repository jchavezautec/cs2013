#include <iostream>

using namespace std;

class Personaje{
private:
    string nombre;
    int vida;
    int ataque;
    int defensa;
    int magia;

public:
    Personaje(string nombre, int vida, int ataque, int defensa, int magia){
        this->nombre = nombre;
        this->vida = vida;
        this->ataque = ataque;
        this->defensa = defensa;
        this->magia = magia;
    }

    Personaje(const Personaje &p){
        //this->nombre = p.nombre;
        this->vida = p.vida;
        this->ataque = p.ataque;
        this->defensa = p.defensa;
        this->magia = p.magia;
    }

    void cambiarNombre(string nombre){
        this->nombre = nombre;
    }

    void mostrar(){
        if(nombre == ""){
            cout << "El personaje no tiene un nombre" << endl;
            return;
        }
        cout << "Nombre: " << nombre << endl;
        cout << "Vida: " << vida << endl;
        cout << "Ataque: " << ataque << endl;
        cout << "Defensa: " << defensa << endl;
        cout << "Magia: " << magia << endl;
    }
};

int main(){
    Personaje p1("Arthas", 100, 50, 30, 100);
    p1.mostrar();

    Personaje p2 = p1;
    p2.mostrar();

    p2.cambiarNombre("Jaina");
    p2.mostrar();

    return 0;
}