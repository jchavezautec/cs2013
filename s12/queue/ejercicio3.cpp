#include <iostream>

using namespace std;

struct Nodo{
    int _item;
    Nodo* _next;
};

class Queue{
    private:
        Nodo* front;
        Nodo* back;
    public:
        Queue(){
            front = NULL;
            back = NULL;
        }
        ~Queue(){
            while(empty()){
                Nodo* temp = front;
                front = front->_next;
                delete temp;
            }
        }
        bool empty(){
            if (front == NULL)
                return true;
            return false;
        }
        void enqueue(int e){
            Nodo* temp = new Nodo;
            temp->_item = e;
            temp->_next = NULL;
            
            if (back ==NULL){
                back = temp;
                front = temp;
            }
            else{
                back->_next = temp;
                back = temp;
            }
        }

        int dequeue(){
            if (!empty()){
                Nodo* temp = front;
                int out = front->_item;
                front = front->_next;

                delete temp;
                if (front == NULL)
                    back = NULL;
            }
            else
                cout << "EMPTY!" << endl;
        }
        void displayQueue(){
            if (empty())
                cout << "Queue empty!" << endl;
            else{
                Nodo* temp = front;
                while (temp != NULL){
                    cout << temp->_item;
                    temp = temp->_next;
                    if (temp == NULL)
                        cout << " <= BACK";
                    cout << endl;
                }
            }
        }
};

int main(){
    Queue myqueue;

    myqueue.dequeue();
    myqueue.enqueue(8);
    myqueue.enqueue(3);
    myqueue.enqueue(7);
    myqueue.enqueue(2);
    myqueue.enqueue(4);
    myqueue.dequeue();
    myqueue.displayQueue();
}