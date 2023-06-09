#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase que representa el estado del juego
class EstadoJuego {
private:
    string nombreNivel;
    int posicionX;
    int posicionY;

public:
    EstadoJuego(const string& nombreNivel, int posicionX, int posicionY)
        : nombreNivel(nombreNivel), posicionX(posicionX), posicionY(posicionY) {}

    string getNombreNivel() const {
        return nombreNivel;
    }

    int getPosicionX() const {
        return posicionX;
    }

    int getPosicionY() const {
        return posicionY;
    }
};

// Clase que representa el Memento
class Memento {
private:
    EstadoJuego estado;

public:
    Memento(const EstadoJuego& estado) : estado(estado) {}

    EstadoJuego getEstado() const {
        return estado;
    }
};

// Clase que representa el personaje del juego
class Personaje {
private:
    string nombre;
    int nivel;
    int puntos;
    vector<Memento*> mementos;

public:
    Personaje(const string& nombre, int nivel, int puntos)
        : nombre(nombre), nivel(nivel), puntos(puntos) {}

    string getNombre() const {
        return nombre;
    }

    int getNivel() const {
        return nivel;
    }

    int getPuntos() const {
        return puntos;
    }

    void setEstado(const EstadoJuego& estado) {
        // Guardar el estado del juego en el Memento
        Memento* memento = new Memento(estado);
        mementos.push_back(memento);
    }

    EstadoJuego getEstado() const {
        // Restaurar el estado del juego desde el Memento
        if (!mementos.empty()) {
            Memento* memento = mementos.back();
            return memento->getEstado();
        }
        // Si no hay mementos, retornar un estado predeterminado
        return EstadoJuego("Nivel 1", 0, 0);
    }
};

int main() {
    // Crear el personaje del juego
    Personaje personaje("Heroe", 1, 0);

    // Jugar y avanzar en el juego
    personaje.setEstado(EstadoJuego("Nivel 1", 10, 20));

    // Guardar el estado actual del juego
    Memento* memento1 = new Memento(personaje.getEstado());

    // Jugar y avanzar en el juego
    personaje.setEstado(EstadoJuego("Nivel 2", 30, 40));

    // Guardar el estado actual del juego
    Memento* memento2 = new Memento(personaje.getEstado());

    // Restaurar el estado del juego al primer punto guardado
    personaje.setEstado(memento1->getEstado());

    cout << "Estado actual del juego: " << personaje.getEstado().getNombreNivel()
        << ", Posicion: (" << personaje.getEstado().getPosicionX() << ", " << personaje.getEstado().getPosicionY() << ")" << endl;

    delete memento1;
    delete memento2;

    return 0;
}
