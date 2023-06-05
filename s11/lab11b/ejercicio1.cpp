#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clase que representa una canción
class Cancion {
private:
    string titulo;
    string artista;

public:
    Cancion(const string& titulo, const string& artista) : titulo(titulo), artista(artista) {}

    string getTitulo() const {
        return titulo;
    }

    string getArtista() const {
        return artista;
    }
};

// Interfaz del iterador
class Iterador {
public:
    virtual bool tieneSiguiente() const = 0;
    virtual Cancion* siguiente() = 0;
};

// Implementación concreta del iterador
class IteradorListaCanciones : public Iterador {
private:
    vector<Cancion*> listaCanciones;
    int indiceActual;

public:
    IteradorListaCanciones(const vector<Cancion*>& listaCanciones) : listaCanciones(listaCanciones), indiceActual(0) {}

    bool tieneSiguiente() const override {
        return indiceActual < listaCanciones.size();
    }

    Cancion* siguiente() override {
        if (tieneSiguiente()) {
            Cancion* cancion = listaCanciones[indiceActual];
            indiceActual++;
            return cancion;
        }
        return nullptr;
    }
};

// Clase que representa el reproductor musical
class ReproductorMusical {
private:
    vector<Cancion*> listaCanciones;

public:
    void agregarCancion(Cancion* cancion) {
        listaCanciones.push_back(cancion);
    }

    Iterador* crearIterador() {
        return new IteradorListaCanciones(listaCanciones);
    }
};

int main() {
    ReproductorMusical reproductor;

    // Crear canciones
    Cancion cancion1("Cancion 1", "Artista 1");
    Cancion cancion2("Cancion 2", "Artista 2");
    Cancion cancion3("Cancion 3", "Artista 3");

    // Agregar canciones al reproductor
    reproductor.agregarCancion(&cancion1);
    reproductor.agregarCancion(&cancion2);
    reproductor.agregarCancion(&cancion3);

    // Obtener el iterador y reproducir las canciones
    Iterador* iterador = reproductor.crearIterador();
    while (iterador->tieneSiguiente()) {
        Cancion* cancion = iterador->siguiente();
        cout << "Reproduciendo: " << cancion->getTitulo() << " - " << cancion->getArtista() << endl;
    }

    delete iterador;

    return 0;
}
