#include <iostream>
#include <vector>

using namespace std;

// Observador abstracto
class Observador {
public:
    virtual void actualizar() = 0;
};

// Observador concreto
class ObservadorConcreto : public Observador {
public:
    void actualizar() override {
        cout << "ObservadorConcreto ha sido notificado" << endl;
        // Realizar acciones específicas de actualización
    }
};

// Sujeto observable
class Sujeto {
private:
    vector<Observador*> observadores;
    bool cambio;

public:
    void agregarObservador(Observador* observador) {
        observadores.push_back(observador);
    }

    void notificarObservadores() {
        if (cambio) {
            for (Observador* observador : observadores) {
                observador->actualizar();
            }
        }
    }

    void setCambio(bool valor) {
        cambio = valor;
        if (cambio) {
            notificarObservadores();
        }
    }
};

int main() {
    Sujeto sujeto;

    ObservadorConcreto observador1;
    sujeto.agregarObservador(&observador1);

    // ...

    sujeto.setCambio(true);

    return 0;
}
