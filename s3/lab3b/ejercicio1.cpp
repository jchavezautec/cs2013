#include <iostream>

using namespace std;

template<int n = 2>
class Polinomio{
    public:
    void print(){
        string s = "";
        s += to_string(rand() % 100);
        s += "x^";
        s += to_string(n);

        for(int i=n-1; i>=0; i--){
            int r = rand() % 100;
            if(r > 0){
                s += " + ";
                s += to_string(r);
                if (i > 0){
                    s += "x^";
                    s += to_string(i);
                }
            }
        }
        cout << s << endl;
    }
};

int main(){
    srand(time(NULL));

    Polinomio<4> pol1;
    pol1.print();       // Resultado: 3x^4 + 6x^3 + 7x^2 + 5x^1 + 3

    Polinomio pol2;
    pol2.print();       // Resultado: 5x^2 + 6x^1 + 2

    Polinomio<11> pol3;
    pol3.print();       // Resultado: 5x^2 + 6x^1 + 2

}