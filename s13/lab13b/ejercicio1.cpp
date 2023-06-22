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

    // Ejercicio 1: Encontrar el padre de un nodo
    Nodo* padreAux(Nodo*,int);  
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

    // Ejercicio 1: Encontrar el padre de un nodo
    Nodo* padre(int);
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

// Ejercicio 1: Encontrar el nodo padre de un nodo dado
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

int main() {
    BST arbol;

    // Insertar nodos en el árbol
    arbol.insertarNodo(50);
    arbol.insertarNodo(30);
    arbol.insertarNodo(20);
    arbol.insertarNodo(40);
    arbol.insertarNodo(60);
    arbol.insertarNodo(10);
    arbol.insertarNodo(5);

    // Imprimir Arbol
    arbol.imprimirPreOrden();
    
    // Encontrar el padre de un nodo
    Nodo* padre = arbol.padre(5);
    if (padre != nullptr)
        cout << "El padre de 5 es: " << padre->dato << endl;
    else
        cout << "El nodo 5 no tiene padre" << endl;
    
    padre = arbol.padre(50);
    if (padre != nullptr)
        cout << "El padre de 50 es: " << padre->dato << endl;
    else
        cout << "El nodo 50 no tiene padre" << endl;

    padre = arbol.padre(60);
    if (padre != nullptr)
        cout << "El padre de 60 es: " << padre->dato << endl;
    else
        cout << "El nodo 60 no tiene padre" << endl;
       
    return 0;
}
