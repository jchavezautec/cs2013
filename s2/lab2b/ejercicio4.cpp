#include <iostream>

using namespace std;

struct Numero{
    virtual int termino(int) = 0;
};

struct Primo: public Numero{
    int termino(int n){
        int cont = 0;
        int i = 2;
        while(cont < n){
            int j = 2;
            while(j < i){
                if(i%j == 0){
                    break;
                }
                j++;
            }
            if(j == i){
                cont++;
            }
            i++;
        }
        return i-1;
    }
};

struct CuadradoPerfecto: public Numero{
    int termino(int n){
        return n*n;
    }
};

struct Fibonacci: public Numero{
    int termino(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return termino(n-1) + termino(n-2);
    }
};
void print_termino_n(Numero* num, int n){
    cout << num->termino(n) << endl;
}

int main(){
    Numero *n1 = new Primo;
    Numero *n2 = new CuadradoPerfecto;
    Numero *n3 = new Fibonacci;
    
    print_termino_n(n1, 5);
    print_termino_n(n2, 5);
    print_termino_n(n3, 5);

    return 0;
}






