#include <iostream>
#include <vector>
using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
  int dato;
  Nodo* left;
  Nodo* right;
  Nodo(int dato): dato(dato), left(nullptr), right(nullptr) {}
};

// Definición de la clase BST (Árbol Binario de Búsqueda)
class BST {
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo*, int);

    // Funciones Auxiliares
    void imprimirPreOrdenAux(Nodo* nodo);
    Nodo* buscarNodoAux(Nodo*, int);
    Nodo* padreAux(Nodo*,int);  

    // Ejercicio 2: Eliminar un nodo
    Nodo* encontrarSucesorAux(Nodo*, int);
    void eliminarAux(Nodo*, int);
    
public:
    // Constructor
    BST();
    BST(vector<int> preorden);
    ~BST();
    void insertarNodo(int);

    // Funcion PreOrden
    void imprimirPreOrden();
    void destruirArbol(Nodo*);
    Nodo* buscarNodo(int);
    Nodo* padre(int);

    // Ejercicio 2: Eliminar un nodo del árbol con el dato dado
    Nodo* encontrarSucesor(int);
    void eliminar(int);
    
};

// Constructor
BST::BST(): raiz(nullptr) {}

// Constructor
BST::BST(vector<int> preorden) {
  raiz = nullptr;
  for (int i = 0; i < preorden.size(); i++) {
    insertarNodo(preorden[i]);
  }
}
// Insertar un nodo en el árbol
void BST::insertarNodo(int dato) {
  raiz = insertarNodoAux(raiz, dato);
}

// Función auxiliar para insertar un nodo en el árbol
Nodo* BST::insertarNodoAux(Nodo* nodo, int dato) {
  if (nodo == nullptr)
    return new Nodo(dato);

  if (dato < nodo->dato)
    nodo->left = insertarNodoAux(nodo->left, dato);
  else if (dato >= nodo->dato)
    nodo->right = insertarNodoAux(nodo->right, dato);
  return nodo;
}

// Buscar un nodo en el árbol
Nodo* BST::buscarNodo(int dato) {
  return buscarNodoAux(raiz, dato);
}

// Función auxiliar para buscar un nodo en el árbol
Nodo* BST::buscarNodoAux(Nodo* nodo, int dato) {
  if (nodo == nullptr || nodo->dato == dato)
    return nodo;

  if (dato < nodo->dato)
    return buscarNodoAux(nodo->left, dato);
  else
    return buscarNodoAux(nodo->right, dato);
}

// Función para imprimir los nodos en preorden
void BST::imprimirPreOrden() {
  imprimirPreOrdenAux(raiz);
  cout << endl;
}

// Función auxiliar para imprimir los nodos en preorden
void BST::imprimirPreOrdenAux(Nodo* nodo) {
  if (nodo == nullptr) {
    return;
  }

  cout << nodo->dato << " ";
  imprimirPreOrdenAux(nodo->left);
  imprimirPreOrdenAux(nodo->right);
}

BST::~BST() {
  destruirArbol(raiz);
}

// Función auxiliar para destruir el árbol utilizando un recorrido PostOrden
void BST::destruirArbol(Nodo* nodo) {
  if (nodo == nullptr) {
    return;
  }
  destruirArbol(nodo->left);
  destruirArbol(nodo->right);
  delete nodo;
}

Nodo* BST::padre(int x){
    return padreAux(raiz, x);
}

Nodo* BST::padreAux(Nodo* nodo, int x){
    if (nodo == nullptr)
        return nullptr;
    if (raiz->dato == x)
        return nullptr;
    if (nodo->left != nullptr && nodo->left->dato == x)
        return nodo;
    if (nodo->right != nullptr && nodo->right->dato == x)
        return nodo;
    if (x < nodo->dato)
        return padreAux(nodo->left, x);
    else
        return padreAux(nodo->right, x);
}

// Ejercicio 2: Eliminar un nodo del árbol

// Método para encontrar el sucesor de un nodo
Nodo* BST::encontrarSucesor(int dato) {
    return encontrarSucesorAux(raiz, dato);
}

// Función auxiliar para encontrar el sucesor de un nodo
Nodo* BST::encontrarSucesorAux(Nodo* nodo, int dato) {
    if (nodo == nullptr)
        return nullptr;
    if (nodo->dato <= dato)
        return encontrarSucesorAux(nodo->right, dato);
    else{
        Nodo* sucesor = encontrarSucesorAux(nodo->left, dato);
        if (sucesor == nullptr)
            return nodo;
        else
            return sucesor;
    }
}

void BST::eliminar(int x){
    Nodo* nodo = buscarNodo(x);
    eliminarAux(nodo, x);
}

void BST::eliminarAux(Nodo* nodo, int x){
    if (nodo == nullptr)
        return;
    Nodo* nodo_padre = padre(x);

    // Caso 1: El nodo es una hoja
    if (nodo->left == nullptr && nodo->right == nullptr){
        if (nodo_padre == nullptr)
            raiz = nullptr;
        else if (nodo_padre->left == nodo)
            nodo_padre->left = nullptr;
        else
            nodo_padre->right = nullptr;
        delete nodo;
    }

    // Caso 2: El nodo tiene un hijo
    else if (nodo->left == nullptr || nodo->right == nullptr){
        Nodo* hijo = nodo->left;
        if (hijo == nullptr)
            hijo = nodo->right;
        if (nodo_padre == nullptr)
            raiz = hijo;
        else if (nodo_padre->left == nodo)
            nodo_padre->left = hijo;
        else
            nodo_padre->right = hijo;
        delete nodo;
    }

    // Caso 3: El nodo tiene dos hijos
    else{
        Nodo* sucesor = encontrarSucesor(x);
        int dato = sucesor->dato;
        eliminarAux(sucesor, dato);
        nodo->dato = dato;
    }
}

int main() {
    BST arbol;
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);
    arbol.insertarNodo(70);
    arbol.insertarNodo(10);
    arbol.insertarNodo(5);

    arbol.imprimirPreOrden(); // Salida: 50 30 20 10 5 40 60 70
    
    arbol.eliminar(50);
    arbol.imprimirPreOrden(); // Salida: 60 30 20 10 5 40 70
}
