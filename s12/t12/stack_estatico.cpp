#include <iostream>

using namespace std;

template<typename T>
class PilaEstatica{
private:
    static const int MAX = 3;
    int top_index;
    T stack[MAX];
public:
    PilaEstatica();
    bool empty();
    bool full();
    void push(T);
    void pop();
    T top();
};

template<typename T>
PilaEstatica<T>::PilaEstatica(): top_index(-1){}

template<typename T>
bool PilaEstatica<T>::empty(){
    return top_index == -1;
}

template<typename T>
bool PilaEstatica<T>::full(){
    return top_index == MAX - 1;
}

template<typename T>
void PilaEstatica<T>::push(T element){
    if(full()){
        cout << "Error: Pila llena" << endl;
        return;
    }
    stack[++top_index] = element;
}

template<typename T>
void PilaEstatica<T>::pop(){
    if(empty()){
        cout << "Error: Pila vacia" << endl;
        return;
    }
    top_index--;
}

template<typename T>
T PilaEstatica<T>::top(){
    if(empty()){
        cout << "Error: Pila vacia" << endl;
        return T();
    }
    return stack[top_index];
}

// Interfaz de la clase PilaEstatica
int main(){
    PilaEstatica<int> p;
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5); // Salida: Error: Pila llena

    cout << "top = " << p.top() << endl; // Salida: top = 4
    p.pop();
    p.pop();
    p.pop();
    cout << "top = " << p.top() << endl; // Salida: top = 3

    return 0;
}