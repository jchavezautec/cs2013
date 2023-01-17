#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

template<int n = 2, class T = int>
class Polinomio{
    public:
    void print(){
        for(int i=0; i<n + 1; i++){
            T num = rand() % 1001 - 500;
            if (num > 0 && i > 0)
                cout << "+";
            cout << setprecision(2);
            cout << num / 100 ;
            if (i < n){
                cout << "x^" << (n-i);
            }
        }
        cout << endl;
    }
};

int main(){
    srand(time(NULL));
    Polinomio<3, float> pol1;
    pol1.print();       // Resultado: 0.17x^3+2.9x^2+3.1x^1+3.8

    Polinomio<4> pol2;
    pol2.print();       // Resultado: -4x^4-2x^30x^2+3x^1-2

    Polinomio pol3;
    pol3.print();       // Resultado: 0x^2+1x^1-3
}