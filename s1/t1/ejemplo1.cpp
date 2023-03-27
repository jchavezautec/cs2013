#include <iostream>
#include <vector>
using namespace std;

class Alumno{
public:
    Alumno() = default;
    Alumno(const Alumno&);
    Alumno(string s): nombre(s){}
    void ingresar_nota(int nota);
private:
    string nombre;
    //int edad;
    vector<int> notas;

    friend ostream &print(ostream&, const Alumno&);
};

Alumno::Alumno(const Alumno& item):
    nombre(item.nombre),
    notas(item.notas)
{}

void Alumno::ingresar_nota(int nota){
    notas.push_back(nota);
}

ostream &print(ostream& os, const Alumno& item){
    float promedio = 0.;
    for(const int nota: item.notas)
        promedio += nota;
    promedio = promedio/item.notas.size();
    os << "Alumno: " << item.nombre << ", ";
    os << "Promedio: " << promedio << endl;
    return os;
}

int main(){
    Alumno obj1("Julian");
    obj1.ingresar_nota(11);
    obj1.ingresar_nota(17);
    obj1.ingresar_nota(8);

    print(cout , obj1);

    Alumno obj2 = obj1;
    print(cout, obj2);
}