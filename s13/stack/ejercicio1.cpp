#include <iostream>

using namespace std;

class Pila{
    private:
        static const int MAX = 3;
        int head;
        int var[MAX];
    public:
        Pila(){ head = -1;}
        bool empty(){
            if (head == -1)
                return true;
            return false;
        }
        bool full(){
            if (head == MAX - 1)
                return true;
            return false;
        }
        void push(int e){
            if (!full())
                var[++head]=e;
            else
                cout << "FULL!" << endl;
        }
        int pop(){
            if (!empty())
                return var[head--];
            else{
                cout << "NO ES POSIBLE!" << endl;
                return  0;
            }
        }
};

int main(){
    Pila p;
    p.push(2);
    p.push(3);
    p.push(4);

    int e = p.pop();
    cout << "e = " << e << endl;

    return 0;
}