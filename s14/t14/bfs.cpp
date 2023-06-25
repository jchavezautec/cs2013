#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

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

    // Algoritmo BFS
    void BFS(Nodo<T>* nodo);
    void recorrerGrafoBFS(T valor);

    // Camino más corto
    void caminoMasCorto(T origen, T destino);
    unordered_map<T,T> caminoBFS(Nodo<T>* origen, Nodo<T>* destino);
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
void Grafo<T>::recorrerGrafoBFS(T valor) {
    Nodo<T>* nodo = buscarNodo(valor);
    if (nodo != nullptr) {
        // Reiniciar los visitados
        for (Nodo<T>* nodo : nodos)
            nodo->visitado = false;
        BFS(nodo);
        cout << endl;
    }
    else
        cout << "Nodo no encontrado" << endl;
}

template<typename T>
void Grafo<T>::BFS(Nodo<T>* nodo) {
    queue<Nodo<T>*> cola;
    cola.push(nodo);

    while (!cola.empty()) {
        Nodo<T>* nodoActual = cola.front();
        cola.pop();

        if (nodoActual->visitado)
            continue;

        nodoActual->visitado = true;
        cout << nodoActual->valor << " ";

        for (Nodo<T>* adyacente : nodoActual->adyacentes) {
            cola.push(adyacente);
        }
    }
}

// Algoritmo de camino más corto
template<typename T>
void Grafo<T>::caminoMasCorto(T origen, T destino) {
    Nodo<T>* nodoOrigen = buscarNodo(origen);
    Nodo<T>* nodoDestino = buscarNodo(destino);

    if (nodoOrigen != nullptr && nodoDestino != nullptr) {
        // Reiniciar los visitados
        for (Nodo<T>* nodo : nodos)
            nodo->visitado = false;
        unordered_map<T,T> padres = caminoBFS(nodoOrigen, nodoDestino);   

        cout << "Camino mas corto: ";
        T nodoActual = destino;
        while (nodoActual != origen) {
            cout << nodoActual << " ";
            nodoActual = padres[nodoActual];
        }
        cout << origen << endl;    
    }
    else
        cout << "Nodo no encontrado" << endl;
}

template<typename T>
unordered_map<T,T> Grafo<T>::caminoBFS(Nodo<T>* origen, Nodo<T>* destino) {
    cout << "Recorrido BFS: ";
    queue<Nodo<T>*> cola;
    cola.push(origen);
    unordered_map<T,T> padres;
    padres[origen->valor] = origen->valor;
    while (!cola.empty()) {
        Nodo<T>* nodoActual = cola.front();
        cola.pop();

        if (nodoActual->visitado) continue;
        nodoActual->visitado = true;
        cout << nodoActual->valor << " ";
        if (nodoActual == destino)
            break;
        for (Nodo<T>* adyacente : nodoActual->adyacentes) {
            cola.push(adyacente);
            if (padres.find(adyacente->valor) == padres.end())
                padres[adyacente->valor] = nodoActual->valor;
        }
    }
    cout << endl;
    return padres;
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
    
    grafo.recorrerGrafoBFS('A');    // Salida: A C B E E
    grafo.caminoMasCorto('A', 'E'); // Salida: A C B E

    return 0;
}
