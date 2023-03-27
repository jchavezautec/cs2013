/*
Implemente la clase Matriz2D con las siguientes caracteristicas:
1.  Implemente la clase Matriz2D, donde cada objeto represente una matriz de dos dimensiones. El constructor debería configurar el tamaño de la matriz.
2.  Para almacenar los elementos de la matriz utilice una matriz dinámica. Los elementos de la matriz deben de ser aleatorio, y entre 0 y 9. Implemente también el destructor.
3.  Implemente un constructor por defecto que establezca una matriz cuadrada de 3x3.
4.  Implemente otro constructor en el caso se ingrese solo una dimensión, por ejemplo "n". Entonces el constructor debería crear una matriz cuadrada de "nxn".
5.  Implemente la función externa "print" que imprima la matriz.
*/

#include <iostream>
#include <cmath>

using namespace std;

class Matriz2D{
public:
    Matriz2D(){
        n = 3;
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
    Matriz2D(int n): n(n){
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
        for(int i = 0; i < n; i++){
            delete[] ptr[i];
        }
        delete[] ptr;
        ptr = NULL;
    }
    friend ostream &print(ostream&, const Matriz2D&); 
private:
    int n;
    int** ptr;
};

ostream &print(ostream& os, const Matriz2D& item){
    for(int i = 0; i < item.n; i++){
        for(int j = 0; j < item.n; j++){
            os << item.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main(){
    Matriz2D obj1(5);
    print(cout, obj1);

    Matriz2D obj2;
    print(cout, obj2);
}