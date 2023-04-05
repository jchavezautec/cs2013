#include <iostream>

using namespace std;

class Dados{
private:
    int *valores;
    int cantidad;

public:
    Dados(int cantidad){
        this->cantidad = cantidad;
        valores = new int[cantidad];
    }

    Dados(const Dados &d){
        this->cantidad = d.cantidad;
        valores = new int[cantidad];
        for(int i = 0; i < cantidad; i++){
            valores[i] = d.valores[i];
        }
    }

    Dados(Dados &&d){
        this->cantidad = d.cantidad;
        valores = d.valores;
        d.valores = nullptr;
    }

    void lanzar(){
        int suma = 0;
        for(int i = 0; i < cantidad; i++){
            valores[i] = rand() % 6 + 1;
            suma += valores[i];
        }
        if(suma / cantidad >= 4){
            cout << "Ganaste!" << endl;
        }else{
            cout << "Perdiste!" << endl;
        }
    }

    void mostrar(){
        for(int i = 0; i < cantidad; i++){
            cout << valores[i] << " ";
        }
        cout << endl;
    }

    ~Dados(){
        delete[] valores;
    }
};

int main(){
    int cantidad;
    cout << "Cantidad de dados: ";
    cin >> cantidad;
    
    Dados d1(cantidad);
    d1.lanzar();
    d1.mostrar();

    Dados d2 = d1;
    d2.mostrar();

    Dados d3 = move(d1);
    d3.mostrar();

    return 0;
}

