#include <iostream>

using namespace std;

class Nodo{
    private:
        int _valor;
        Nodo *_next;
    public:
        Nodo(int valor, Nodo* next){
            _valor = valor;
            _next  = next;
        }
        int getValor(){ return _valor;}

        Nodo* getNext(){ return _next;}
};

int main(){
    // Resultado: 3
    Nodo* n1 = new Nodo(3, NULL);
    cout << "valor = " << n1->getValor() << endl;

    // Resultado: 5
    Nodo* n2 = new Nodo(5, n1);
    cout << "valor = " << n2->getValor() << endl;

    // Resultado: 3
    cout << "valor = " << n2->getNext()->getValor() << endl;

    Nodo* top = n2;
    top = n2->getNext();
    delete n2;
    delete top; // delete n1

    delete n1; // Error: double free
}