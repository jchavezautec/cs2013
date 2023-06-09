#include <iostream>
#include <vector>

using namespace std;

class Memento {
private:
    string state;

public:
    Memento(const string& s) : state(s) {}

    string getState() const {
        return state;
    }
};

class Lienzo {
private:
    string contenido;

public:
    void dibujar(const string& figura) {
        cout << "Dibujando " << figura << endl;
        contenido += figura + ' ';
    }

    Memento guardarEstado() const {
        return Memento(contenido);
    }

    void restaurarEstado(const Memento& memento) {
        contenido = memento.getState();
    }

    string getContenido() const {
        return contenido;
    }
};

class Historial {
private:
    vector<Memento> estados;

public:
    void agregarEstado(const Memento& estado) {
        estados.push_back(estado);
    }

    Memento getEstadoAnterior() {
        if (estados.size() > 1) {
            estados.pop_back();
            return estados.back();
        }

        return Memento("");
    }
};

int main() {
    Lienzo lienzo;
    Historial historial;

    lienzo.dibujar("Cuadrado");
    historial.agregarEstado(lienzo.guardarEstado());

    lienzo.dibujar("Circulo");
    historial.agregarEstado(lienzo.guardarEstado());

    lienzo.dibujar("Triangulo");
    historial.agregarEstado(lienzo.guardarEstado());

    cout << "Estado actual del lienzo: " << lienzo.getContenido() << endl;
    // Restaurar el estado anterior
    Memento estadoAnterior = historial.getEstadoAnterior();
    lienzo.restaurarEstado(estadoAnterior);

    // Imprimir el estado actual del lienzo
    cout << "Estado actual del lienzo: " << lienzo.getContenido() << endl;

    return 0;
}
