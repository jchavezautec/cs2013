#include <iostream>
#include <cmath>

using namespace std;

class Matriz2D{
public:
    Matriz2D(int n, int m): n(n), m(m){
        // Crear matriz dinamica (ptr) de n filas
        ptr = new int*[n];

        // Crear cada fila de la matriz dinamica (ptr) de m columnas
        for(int i = 0; i < n; i++){
            ptr[i] = new int[m];
        }

        // Inicializar la matriz dinamica (ptr) con numeros aleatorios entre 0 y 9
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptr[i][j] = rand() % 10;
            }
        }
    }
    Matriz2D(): n(3), m(3){
        ptr = new int*[n];
        for(int i = 0; i < n; i++){
            ptr[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ptr[i][j] = rand() % 10;
            }
        }
    }
    Matriz2D(int n): n(n),m(n){
        ptr = new int*[n];
        for(int i = 0; i < n; i++){
            ptr[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ptr[i][j] = rand() % 10;
            }
        }
    }
    ~Matriz2D(){
        // Liberar memoria de la matriz dinamica (ptr) 
        for(int i = 0; i < n; i++){
            // Liberar memoria de cada fila
            delete[] ptr[i];
        }
        // Liberar memoria del puntero
        delete[] ptr;

        // Asignar NULL a ptr
        ptr = NULL;
    }
    friend ostream &print(ostream&, const Matriz2D&); 
private:
    int n;
    int m;
    int** ptr;
};

ostream &print(ostream& os, const Matriz2D& item){
    for(int i = 0; i < item.n; i++){
        for(int j = 0; j < item.m; j++){
            os << item.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main(){
    Matriz2D obj1(2,3);
    print(cout, obj1);
    cout << endl;

    Matriz2D obj2(5);
    print(cout, obj2);
    cout << endl;

    Matriz2D obj3;
    print(cout, obj3);
}