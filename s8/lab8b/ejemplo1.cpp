#include <iostream>
using namespace std;
 
class Vehiculo {
public:
    /* 
    Esta solo puede ser una clase base, no
    se pueden crear instancias de esta clase 
    */
    virtual void print() = 0;
};
class Moto: public Vehiculo {
public:
    void print(){
        cout << "Moto..." << endl;
    }
};
class Carro: public Vehiculo {
public:
    void print(){
        cout << "Carro..." << endl;
    }
};
 
class Cliente {
private:
    Vehiculo* _inst;
public:
    Cliente(int tipo_vehiculo){
        if (tipo_vehiculo == 1)
            _inst = new Moto();
        else if (tipo_vehiculo == 2)
            _inst = new Carro();
        else
            _inst = NULL;
    } 
    ~Cliente(){
        if (_inst) {
            delete _inst;
            _inst = NULL;
        }
    }
    Vehiculo* getVehiculo() { return _inst; }
};
 
int main()
{
    Cliente* pt r_cliente = new Cliente(1);
    Vehiculo* ptr_vehiculo = ptr_cliente->getVehiculo();
    ptr_vehiculo->print();
    return 0;
}