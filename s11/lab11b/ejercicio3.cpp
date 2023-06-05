#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Clase observada (Sujeto)
class Usuario;

// Clase observadora (Observer)
class Observer {
public:
    virtual void actualizar(const string& historia) = 0;
};

// Clase observadora concreta (Seguidor)
class Seguidor : public Observer {
private:
    string nombre;

public:
    Seguidor(const string& nombre) : nombre(nombre) {}

    void actualizar(const string& historia) override {
        cout << nombre << " recibio una nueva historia: " << historia << endl;
    }
};

// Clase observada concreta (Usuario)
class Usuario {
private:
    string nombre;
    vector<Observer*> observadores;

public:
    Usuario(const string& nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }

    void agregarObservador(Observer* observador) {
        observadores.push_back(observador);
    }

    void eliminarObservador(Observer* observador) {
        // Buscar y eliminar el observador de la lista de observadores
        auto it = find(observadores.begin(), observadores.end(), observador);
        if (it != observadores.end()) {
            observadores.erase(it);
        }
    }

    void notificarSeguidores(const string& historia) {
        // Notificar a todos los observadores con la nueva historia
        for (Observer* observador : observadores) {
            observador->actualizar(historia);
        }
    }
};

int main() {
    // Crear usuarios y seguidores
    Usuario usuario("Usuario1");
    Seguidor seguidor1("Seguidor1");
    Seguidor seguidor2("Seguidor2");

    // Agregar seguidores al usuario
    usuario.agregarObservador(&seguidor1);
    usuario.agregarObservador(&seguidor2);

    // Publicar una nueva historia
    string nuevaHistoria = "Hoy estoy de viaje!";
    usuario.notificarSeguidores(nuevaHistoria);

    return 0;
}
