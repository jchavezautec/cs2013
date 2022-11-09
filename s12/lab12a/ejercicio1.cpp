#include <iostream>

using namespace std;

// Interfaz del Target
class InterfazPlug { 
public:
    void virtual DosPines(){}
};

// Target
class Plug: public InterfazPlug { 
public:
    void DosPines() {
        cout << " Tengo dos pines" << endl;
    }
};

// Interfaz del Adaptee
class InterfazSwitch { 
public:
    void virtual TresPines() {}
};

// Adaptee
class Switch : public InterfazSwitch {
public:
    void TresPines() {
        cout << "En la habitacion solo hay de tres pines" << endl;
    }
};

// Adapter
class Adapter : public InterfazPlug {
public:
    InterfazSwitch *_interfaz_switch;
    Adapter(InterfazSwitch *interfaz_switch) {
            _interfaz_switch = interfaz_switch;
    }
    void DosPines() { _interfaz_switch->TresPines();}
};

// Cliente
int main(){
    // Adaptee
    Switch *mySwitch = new Switch; 

    // Target <= Adapter(Adaptee)
    InterfazPlug *adapter = new Adapter(mySwitch);
    adapter->DosPines();
}