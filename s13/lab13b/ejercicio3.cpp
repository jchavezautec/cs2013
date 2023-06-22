#include <iostream>
#include <string>
using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    string nombre;
    int precio;
    Nodo* left;
    Nodo* right;
    Nodo(string nombre, int precio): nombre(nombre), precio(precio), left(nullptr), right(nullptr) {}
};

// Definición de la clase BST (Árbol Binario de Búsqueda)
class BST {
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo*, string, int);
    Nodo* buscarNodoAux(Nodo*, string);
    void destruirArbol(Nodo*);
    void InOrderAux(Nodo*);
public:
    // Constructor
    BST();
    ~BST();
    void insertarNodo(string, int);
    Nodo* buscarNodo(string);
    void InOrder();
};

// Constructor
BST::BST(): raiz(nullptr) {}

// Destructor
BST::~BST() {
    // Invocar una función auxiliar para liberar la memoria de los nodos
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

// Insertar un nodo en el árbol
void BST::insertarNodo(string nombre, int precio) {
  raiz = insertarNodoAux(raiz, nombre, precio);
}

// Función auxiliar para insertar un nodo en el árbol
Nodo* BST::insertarNodoAux(Nodo* nodo, string nombre, int precio) {
  if (nodo == nullptr)
    return new Nodo(nombre, precio);

  if (nombre < nodo->nombre)
    nodo->left = insertarNodoAux(nodo->left, nombre, precio);
  else if (nombre > nodo->nombre)
    nodo->right = insertarNodoAux(nodo->right, nombre, precio);
  return nodo;
}

// Buscar un nodo en el árbol por su nombre
Nodo* BST::buscarNodo(string nombre) {
  return buscarNodoAux(raiz, nombre);
}

// Función auxiliar para buscar un nodo en el árbol
Nodo* BST::buscarNodoAux(Nodo* nodo, string nombre) {
  if (nodo == nullptr || nodo->nombre == nombre)
    return nodo;

  if (nombre < nodo->nombre)
    return buscarNodoAux(nodo->left, nombre);
  else
    return buscarNodoAux(nodo->right, nombre);
}

// Función para imprimir los nodos en InOrder
void BST::InOrder() {
  InOrderAux(raiz);
  cout << endl;
}

// Función auxiliar para imprimir los nodos en InOrder
void BST::InOrderAux(Nodo* nodo) {
  if (nodo == nullptr)
    return;
  InOrderAux(nodo->left);
  cout << nodo->nombre << " ";
  InOrderAux(nodo->right);
}

int main() {
    BST arbol;
    arbol.insertarNodo("Arroz", 45);
    arbol.insertarNodo("Detergente", 30);
    arbol.insertarNodo("Pan", 5);
    arbol.insertarNodo("Aceite", 12);
    arbol.insertarNodo("Donas", 59);

    string x = "Aceite";
    Nodo* nodoProducto = arbol.buscarNodo(x);
    if (nodoProducto != nullptr)
        cout << "Precio: " << nodoProducto->precio << endl;
    else
        cout << "No se encontro el producto" << endl;

    arbol.InOrder(); // Salida: Aceite Arroz Detergente Donas Pan
}
