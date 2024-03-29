#include <iostream>
#include <vector>
using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
  int dato;
  Nodo* left;
  Nodo* right;

  // Constructor
  Nodo(int dato) {
    this->dato = dato;
    left = nullptr;
    right = nullptr;
  }
};

// Definición de la clase BST (Árbol Binario de Búsqueda)
class BST {
private:
    Nodo* raiz;
    Nodo* insertarNodoAux(Nodo* nodo, int dato);
    Nodo* buscarNodoAux(Nodo* nodo, int dato);

    // Funciones auxiliares para imprimir los nodos en diferentes órdenes
    void imprimirEnOrdenAux(Nodo* nodo);
    void imprimirPreOrdenAux(Nodo* nodo);
    void imprimirPostOrdenAux(Nodo* nodo);
    int calcularAlturaAux(Nodo* nodo);

    // Ejercicio 1:
    Nodo* encontrarSucesorAux(Nodo*, int);
public:
    // Constructor
    BST();
    BST(vector<int> preorden);
    ~BST();
    void insertarNodo(int dato);
    Nodo* buscarNodo(int dato);

  // Funciones para imprimir los nodos en diferentes órdenes
    void imprimirEnOrden();
    void imprimirPreOrden();
    void imprimirPostOrden();
    void destruirArbol(Nodo*);
    int calcularAltura();

    // Ejercicio 1:
    Nodo* encontrarSucesor(int);
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
  else if (dato > nodo->dato)
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



// Función para imprimir los nodos en orden
void BST::imprimirEnOrden() {
  imprimirEnOrdenAux(raiz);
  cout << endl;
}

// Función auxiliar para imprimir los nodos en orden
void BST::imprimirEnOrdenAux(Nodo* nodo) {
  if (nodo == nullptr) {
    return;
  }

  imprimirEnOrdenAux(nodo->left);
  cout << nodo->dato << " ";
  imprimirEnOrdenAux(nodo->right);
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

// Función para imprimir los nodos en postorden
void BST::imprimirPostOrden() {
  imprimirPostOrdenAux(raiz);
  cout << endl;
}

// Función auxiliar para imprimir los nodos en postorden
void BST::imprimirPostOrdenAux(Nodo* nodo) {
  if (nodo == nullptr) {
    return;
  }

  imprimirPostOrdenAux(nodo->left);
  imprimirPostOrdenAux(nodo->right);
  cout << nodo->dato << " ";
}

BST::~BST() {
  destruirArbol(raiz);
}

// Función auxiliar para destruir el árbol utilizando un recorrido PostOrden
void BST::destruirArbol(Nodo* nodo) {
  if (nodo == nullptr) {
    return;
  }

  // Recorrer el subárbol izquierdo
  destruirArbol(nodo->left);

  // Recorrer el subárbol derecho
  destruirArbol(nodo->right);

  // Eliminar el nodo actual
  delete nodo;
}

// Altura del Arbol
int BST::calcularAltura() {
  return calcularAlturaAux(raiz);
}

// Función auxiliar para calcular la altura de un nodo
int BST::calcularAlturaAux(Nodo* nodo) {
  if (nodo == nullptr)
    return 0;

  return 1 + max(calcularAlturaAux(nodo->left), calcularAlturaAux(nodo->right));
}

// Ejercicio 1:
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

    // Sucesor de 5
    Nodo* sucesor = arbol.encontrarSucesor(5);
    if (sucesor != nullptr)
        cout << "Sucesor de 5: " << sucesor->dato << endl;
    else
        cout << "No existe sucesor de 5" << endl;

    // Ejemplo de un nodo sin sucesor
    sucesor = arbol.encontrarSucesor(60);
    if (sucesor != nullptr)
        cout << "Sucesor de 60: " << sucesor->dato << endl;
    else
        cout << "No existe sucesor de 60" << endl;
    
    return 0;
}
