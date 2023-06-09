#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T valor, Nodo<T>* next): valor(valor), next(next){}
};

template<typename T>
class Pila{
private:
    int size_pila;     // Numero de elementos en la pila
    Nodo<T>* nodo_top; // Puntero al primer nodo de la pila
public:
    Pila();         // Inicializa la pila con nodo_top = NULL
    ~Pila();        // Libera la memoria de todos los nodos de la pila
    bool empty();   // Retorna true si la pila esta vacia
    int size();     // Retorna el numero de elementos en la pila
    void push(T);   // Agrega un elemento a la pila
    void pop();     // Elimina el elemento en el tope(TOP) de la pila
    T top();        // Retorna el elemento en el tope(TOP) de la pila
};

template<typename T>
Pila<T>::Pila(): nodo_top(NULL), size_pila(0){}

template<typename T>
bool Pila<T>::empty(){
    return nodo_top == NULL;
}

// El destructor libera la memoria de todos los nodos
// de la pila usando el metodo pop() hasta que la pila
// este vacia
template<typename T>
Pila<T>::~Pila(){
    while(!empty()){
        pop();
    }
}

// El metodo size() recorre la pila contando el numero
// de nodos hasta que llega al final de la pila (NULL)
template<typename T>
int Pila<T>::size(){
    return size_pila;
}

// El metodo push() agrega un nuevo nodo al inicio
// de la pila (nodo_top), el nodo 'nuevo' ahora apunta 
// al nodo que estaba en el tope de la pila (nodo_top).
// El elemento 'e' se guarda en el nodo 'nuevo'.
template<typename T>
void Pila<T>::push(T e){
    Nodo<T>* nuevo = new Nodo<T>(e, nodo_top);
    nodo_top = nuevo;
    size_pila++;
}

// El metodo pop() elimina el nodo que esta en el tope
// de la pila (nodo_top) y libera la memoria del nodo
// eliminado. El nuevo tope de la pila es el nodo que
// estaba apuntado por el nodo eliminado. 
template<typename T>
void Pila<T>::pop(){
    if(empty()){
        cout << "Error: Pila vacia" << endl;
        return;
    }
    Nodo<T>* temp = nodo_top;
    nodo_top = nodo_top->next;
    delete temp;
    size_pila--;
}

// El metodo top() retorna el elemento que esta en el
// tope de la pila (nodo_top) sin eliminarlo.
template<typename T>
T Pila<T>::top(){
    if(empty()){
        cout << "Error: Pila vacia" << endl;
        return T();
    }
    return nodo_top->valor;
}

int main(){
   Pila<int> pila;
   pila.push(2); // |2|
   pila.push(4); // |2|4|
   pila.push(3); // |2|4|3|
   cout << pila.top() << endl; // 3

   pila.pop();   // |2|4|
   pila.push(9); // |2|4|9|
   pila.pop();   // |2|4|
   cout << "size = " << pila.size() << endl; // size = 2
   cout << pila.top() << endl; // 4

   return 0;
}
