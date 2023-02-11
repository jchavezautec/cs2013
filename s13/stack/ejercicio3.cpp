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

class Pila{
    private:
        Nodo* _top;
    public:
        Pila(){
            _top = NULL;
        }
        ~Pila(){
            Nodo* aux;
            while (_top != NULL){
                aux = _top;
                _top = _top->getNext();
                delete aux;
            }
        }

        void push(int valor){
            // Se crea un nodo nuevo
            Nodo* n = new Nodo(valor, _top);

            // El comienzo de la pila ahora es 
            // el nuevo nodo
            _top = n;
        }

        int pop(){
            int valor;
            
            // Si no hay elementos en la pila
            // retornar 0
            if (_top == NULL)
                return 0;

            // El nodo apunta al primer elemento de la pila
            Nodo* n = _top;

            // El nuevo TOP es el siguiente del TOP actual
            _top = n->getNext();

            // Guardamos el valor del antiguo TOP
            valor = n->getValor();

            // Borramos el nodo
            delete n;
            return valor;
        }
};

int main(){
   Pila pila;
   pila.push(2);
   cout << "Push(2)" << endl;
   pila.push(4);
   cout << "Push(4)" << endl;
   pila.push(3);
   cout << "Push(3)" << endl;
   cout << "Pop() = " << pila.pop() << endl;
   pila.push(9);
   cout << "Push(9)" << endl;
   cout << "Pop() = " << pila.pop() << endl;
   cout << "Pop() = " << pila.pop() << endl;

   return 0;
}
