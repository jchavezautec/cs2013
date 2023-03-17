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

class Foo{
public:
    Foo(int x){ ptr = new int(x);}
    Foo(const Foo& item): ptr(item.ptr){
        cout << "Constructor de Copia" << endl;
    }
    Foo(Foo&& item): ptr(item.ptr){
        item.ptr = NULL;
        cout << "Constructor de Movimiento" << endl;
    }
    print(){cout << *ptr << endl;}
    ~Foo(){
        delete ptr;
        ptr=NULL;
    }
private:
    int* ptr;
};

int main(){
    Alumno obj1("Julian");
    obj1.ingresar_nota(11);
    obj1.ingresar_nota(17);
    obj1.ingresar_nota(8);

    print(cout , obj1);

    Alumno obj2 = obj1;
    print(cout, obj2);

    // Referencias Rvalue
    int i = 7;          // i es un Lvalue, pero 7 es un Rvalue
    int k = i+3;        // (i+3) es un Lvalue
    //int *pi = &(i + 3); 

    int &b1 = i; // OK
    //int &&c1 = a; // ERROR
    //int &b2 = a * 42; // ERROR

    int &&c2 = i * 42;
    int &&c3 = 9;
    const int &d2 = i * 42; // OK

    int &&rr2 = move(c3);

    Foo p1(1);
    Foo p2 = p1;
    p2.print();
    p1.print();

    Foo p3 = move(p1);
    p3.print();
    p1.print();
}