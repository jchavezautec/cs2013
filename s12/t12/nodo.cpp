#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T valor, Nodo<T>* next): valor(valor), next(next){}
};

int main(){
    Nodo<int>* n1 = new Nodo<int>(3, NULL);
    cout << "valor = " << n1->valor << endl; 
    // Salida: valor = 3

    Nodo<int>* n2 = new Nodo<int>(5, n1);
    cout << "valor = " << n2->valor << endl;
    // Salida: valor = 5
    
    cout << "valor = " << n2->next->valor << endl;
    // Salida: valor = 3
}