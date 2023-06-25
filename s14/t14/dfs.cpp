#include <iostream>
#include <unordered_set>

using namespace std;

template<typename T>
class Nodo {
public:
    T valor;
    bool visitado;
    unordered_set<Nodo*> adyacentes;
    Nodo(T val) : valor(val), visitado(false) {}
};

template<typename T>
class Grafo {
private:
    unordered_set<Nodo<T>*> nodos;
public:
    void agregarNodo(T valor);
    Nodo<T>* buscarNodo(T valor);
    void agregarArista(T origen, T destino);

    // Algoritmo DFS
    void DFS(Nodo<T>* nodo);
    void recorrerGrafoDFS(T valor);

    void buclesDFS(Nodo<T>* nodo);
    bool existeBucle(T valor);
};

template<typename T>
void Grafo<T>::agregarNodo(T valor) {
    nodos.insert(new Nodo<T>(valor));
}

template<typename T>
Nodo<T>* Grafo<T>::buscarNodo(T valor) {
    for (Nodo<T>* nodo : nodos)
        if (nodo->valor == valor)
            return nodo;
    return nullptr;
}


template<typename T>
void Grafo<T>::agregarArista(T origen, T destino) {
    Nodo<T>* nodoOrigen = buscarNodo(origen);
    Nodo<T>* nodoDestino = buscarNodo(destino);

    if (nodoOrigen != nullptr && nodoDestino != nullptr)
        nodoOrigen->adyacentes.insert(nodoDestino);
}

template<typename T>
void Grafo<T>::DFS(Nodo<T>* nodo) {
    if (nodo->visitado)
        return;

    nodo->visitado = true;
    cout << nodo->valor << " ";

    for (Nodo<T>* adyacente : nodo->adyacentes) {
        DFS(adyacente);
    }
}

template<typename T>
void Grafo<T>::recorrerGrafoDFS(T valor) {
    Nodo<T>* nodo = buscarNodo(valor);
    if (nodo != nullptr){
        // Reiniciar los visitados
        for (Nodo<T>* nodo : nodos)
            nodo->visitado = false;
        DFS(nodo);
        cout << endl;
    }
    else
        cout << "Nodo no encontrado" << endl;
}

template<typename T>
void Grafo<T>::buclesDFS(Nodo<T>* nodo) {
    if (nodo->visitado)
        return;
    nodo->visitado = true;
    cout << nodo->valor << " ";

    for (Nodo<T>* adyacente : nodo->adyacentes) {
        if (adyacente->visitado) {
            cout << "Bucle encontrado" << endl;
            return;
        }
        buclesDFS(adyacente);
    }
}

template<typename T>
bool Grafo<T>::existeBucle(T valor) {
    // utilizando el DFS
    Nodo<T>* nodo = buscarNodo(valor);
    if (nodo != nullptr) {
        // Reiniciar los visitados
        for (Nodo<T>* nodo : nodos)
            nodo->visitado = false;
        buclesDFS(nodo);
    }
    return false;
}

int main() {
    Grafo<char> grafo;

    // Agregar nodos
    grafo.agregarNodo('A');
    grafo.agregarNodo('B');
    grafo.agregarNodo('C');
    grafo.agregarNodo('D');
    grafo.agregarNodo('E');

    // Agregar aristas
    grafo.agregarArista('A', 'B');
    grafo.agregarArista('A', 'C');
    grafo.agregarArista('B', 'C');
    grafo.agregarArista('B', 'D');
    grafo.agregarArista('C', 'E');
    
    // Detectando ciclo en el grafo utilizando DFS
    grafo.recorrerGrafoDFS('A');
    grafo.existeBucle('A');             //  Salida: Bucle encontrado

    return 0;
}
