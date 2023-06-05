#include <iostream>
#include <string>

using namespace std;

// Interfaz del reproductor de música existente
class Reproductor {
public:
    virtual void reproducirWAV(const string& archivo) const = 0;
};

// Implementación del reproductor de música existente
class ReproductorWAV : public Reproductor {
public:
    void reproducirWAV(const string& archivo) const override {
        // Implementación para reproducir archivos WAV
        cout << "Reproduciendo archivo WAV: " << archivo << endl;
    }
};

// Interfaz del reproductor de música adaptado para archivos MP3
class ReproductorMP3 {
public:
    virtual void reproducirMP3(const string& archivo) const = 0;
};

// Implementación del reproductor de música adaptado para archivos MP3
class AdaptadorMP3 : public ReproductorMP3 {
private:
    Reproductor* reproductor;

public:
    AdaptadorMP3(Reproductor* reproductor) : reproductor(reproductor) {}

    void reproducirMP3(const string& archivo) const override {
        // Lógica de adaptación para reproducir archivos MP3 utilizando 
        // el reproductor existente
        cout << "Adaptador: Reproduciendo archivo MP3" << endl;
        reproductor->reproducirWAV(archivo);
    }
};

int main() {
    // Crear el reproductor WAV
    ReproductorWAV reproductorWAV;

    // Crear el adaptador para reproducir archivos MP3
    ReproductorMP3* adaptadorMP3 = new AdaptadorMP3(&reproductorWAV);

    // Reproducir archivo MP3 utilizando el adaptador
    adaptadorMP3->reproducirMP3("cancion.mp3");

    // Liberar la memoria
    delete adaptadorMP3;

    return 0;
}
