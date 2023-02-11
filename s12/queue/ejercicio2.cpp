#include <iostream>

using namespace std;

struct Nodo{
    int _item;
    Nodo* _next;
};

int main(){
    // Cola vacia
    Nodo* front = NULL;
    Nodo* back = NULL;

    //Enqueue(3)
    Nodo* temp1 = new Nodo;
    temp1->_item = 3;
    temp1->_next = NULL;

    front = temp1;
    back = temp1;

    cout << "front = " << front->_item << endl;
    cout << "back = " << back->_item << endl;

    //Enqueue(5)
    Nodo* temp2 = new Nodo;
    temp2->_item = 5;
    temp2->_next = NULL;
    
    back->_next = temp2;
    back = temp2;

    cout << "front = " << front->_item << endl;
    cout << "back = " << back->_item << endl;
    cout << "next(front) = " << front->_next->_item << endl;
}