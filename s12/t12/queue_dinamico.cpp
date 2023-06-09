#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T valor;
    Nodo<T>* next;
    Nodo(T valor, Nodo<T>* next): valor(valor), next(next){}
};


template<typename T>
class Cola{
private:
    int size_cola;       // Numero de elementos en la cola
    Nodo<T>* nodo_front; // Puntero al frente de la cola
    Nodo<T>* nodo_back;  // Puntero al final de la cola
public:
    Cola();        
    bool empty();  // Retorna true si la cola esta vacia
    int size();    // Retorna el numero de elementos en la cola
    T front();     // Retorna el elemento en el frente de la cola
    T back();      // Retorna el elemento en el final de la cola 
    void push(T);  // Agrega un elemento al final de la cola
    void pop();    // Elimina el elemento en el frente de la cola
};

// El constructor inicializa los atributos de la clase
// donde 'nodo_front' y 'nodo_back' apuntan a NULL y 'size_cola' es 0
template<typename T>
Cola<T>::Cola(): size_cola(0), nodo_front(NULL), nodo_back(NULL){}

// El metodo empty() retorna true si la cola esta vacia
// y false en caso contrario (size_cola == 0) 
template<typename T>
bool Cola<T>::empty(){
    return size_cola == 0;
}

// El metodo size() retorna el numero de elementos en la cola
template<typename T>
int Cola<T>::size(){
    return size_cola;
}

// El metodo front() retorna el elemento en el frente de la cola
template<typename T>
T Cola<T>::front(){
    return nodo_front->valor;
}

// El metodo back() retorna el elemento en el final de la cola
template<typename T>
T Cola<T>::back(){
    return nodo_back->valor;
}

/* 
El metodo push() agrega un nuevo nodo al final de la cola, el
nodo 'nuevo' ahora apunta a NULL y el elemento 'e' se guarda en
el nodo 'nuevo'. Si la cola esta vacia (nodo_front == NULL)
entonces el nodo 'nuevo' tambien es el frente de la cola 
(nodo_front = nuevo) y si la cola no esta vacia entonces el
nodo 'nuevo' se agrega al final de la cola (nodo_back->next = nuevo)
y el nodo 'back' ahora apunta al nodo 'nuevo' (nodo_back = nuevo) 
*/
template<typename T>
void Cola<T>::push(T e){
    Nodo<T>* nuevo = new Nodo<T>(e, NULL);
    if(empty()){
        nodo_front = nuevo;
    }else{
        nodo_back->next = nuevo;
    }
    nodo_back = nuevo;
    size_cola++;
}

/*
El metodo pop() elimina el nodo en el frente de la cola
(front) y el nodo 'nodo_front' ahora apunta al siguiente nodo
en la cola (nodo_front = nodo_front->next). Si la cola esta vacia
(nodo_front == NULL) entonces el nodo 'nodo_back' tambien es NULL
(nodo_back = NULL) y si la cola no esta vacia entonces el
nodo 'nodo_front' se elimina y el nodo 'nodo_back' no cambia
*/
template<typename T>
void Cola<T>::pop(){
    if(!empty()){
        Nodo<T>* tmp = nodo_front;
        nodo_front = nodo_front->next;
        delete tmp;
        size_cola--;
        if(empty()){
            nodo_back = NULL;
        }
    }
}

int main(){
    Cola<int> cola;
    cola.push(7); //    |7|
    cola.push(2); //    |7|2|
    cola.push(5); //    |7|2|5|
    cola.pop();   //    |2|5|
    cout << cola.front() << endl; // 2
    cout << cola.back() << endl;  // 5

    return 0;
}
