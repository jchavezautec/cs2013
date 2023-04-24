#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

template<int n = 2, class T = int>
class Polinomio{
    public:
    void print(){
        T r = rand() % 1001 - 500;
        cout << r/10 << "x^" << n;

        for(int i=n-1; i>=0; i--){
            T r = rand() % 1000 - 500;
            if(r > 0){
                cout << '+' << r/10;
                if (i > 0){
                    cout << "x^" << i;
                }
            }
            else{
                cout << '-' << -1 * r/10;
                if (i > 0){
                    cout << "x^" << i;
                }                
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