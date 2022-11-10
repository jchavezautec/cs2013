#include <iostream>

using namespace std;

class Queue{
    private:
        static const int MAX = 10;
        int items[MAX];
        int front;
        int back;
    public:
        Queue(){
            front = -1;
            back  = -1;
        }
        bool full(){
            if (front == 0 && back == MAX - 1)
                return true;
            return false;
        }
        bool empty(){
            if (front == -1)
                return true;
            return false;
        }
        void enqueue(int e){
            if (full())
                cout << "FULL!" << endl;
            else{
                if (front == -1){ front = 0;}
                back++;
                items[back] = e;
            }
        }
        int dequeue(){
            if (empty()){
                cout << "EMPTY!" << endl;
                return -1;
            }
            else{
                int e = items[front];
                if (front >= back){
                    front = -1;
                    back = -1;
                }
                else
                    front++;
                cout << "e = "<< e;
                cout << " deleted!" << endl;
                return e;
            }   
        }
        void displayQueue(){
            if (empty())
                cout << "Queue empty!" << endl;
            else{
                cout << "\nQUEUE:" << endl;
                for (int i=front; i <= back; i++){
                    if (i == front)
                        cout << items[i] << " <= HEAD" << endl;
                    else if (i == back)
                        cout << items[i] << " <= BACK" << endl;
                    else
                        cout << items[i] << endl;
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