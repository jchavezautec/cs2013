// Implemetar la clase Vector3D, con la siguientes caracteristicas:
// 1. Cada objeto represente una coordenada en tres dimensiones de un vector. El constructor
//    deber ́ıa configurar las tres coordenadas
// 2. Para almacenar los elementos del vector, utilice un array dinamico.
// 3. Implemente un constructor por defecto que genere un vector NULO.
// 4. Implemente el método "modulo". Este método debe calcular el módulo del vector.
// 5. Implemente una funcion externa "print" que imprima las coordenadas del vector.
// 6. Implemente el destructor.


#include <iostream>
#include <cmath>

using namespace std;

class Vector3D{
private:
    float* ptr;
public:
    Vector3D(){
        ptr = new float[3];
        for(int i = 0; i < 3; i++){
            ptr[i] = 0;
        }
    }
    Vector3D(float x, float y, float z){
        ptr = new float[3];
        ptr[0] = x;
        ptr[1] = y;
        ptr[2] = z;
    }
    ~Vector3D(){
        delete[] ptr;
        ptr = NULL;
    }
    float modulo(){
        return sqrt(ptr[0]*ptr[0] + ptr[1]*ptr[1] + ptr[2]*ptr[2]);
    }

    friend ostream &print(ostream&, const Vector3D&);
};

ostream &print(ostream& os, const Vector3D& item){
    for(int i = 0; i < 3; i++){
        os << item.ptr[i] << " ";
    }
    os << endl;
    return os;
}

int main(){
    Vector3D obj1(1, 2, 3);
    print(cout, obj1);
    cout << "Modulo: " << obj1.modulo() << endl;
}
