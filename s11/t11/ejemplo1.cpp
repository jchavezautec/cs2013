// ADAPTER

#include <iostream>
using namespace std;

// Interfaz Abstracta para todos los formatos de imagen
class IFormatoImagen {
public:
    virtual void mostrar() = 0;
};

// Clase para imágenes en formato JPEG
class JPEGImagen : public IFormatoImagen {
public:
    void mostrar() {
        // Lógica para mostrar la imagen JPEG en pantalla
        cout << "Mostrando imagen JPEG..." << endl;
    }
};

class PNGImagen {
public:
    void mostrarPNG() {
        // Lógica para visualizar la imagen PNG en pantalla
        cout << "Mostrando imagen PNG..." << endl;
    }
};

// Clase Adapter para adaptar imágenes en formato PNG
class AdapterPNG : public IFormatoImagen {
private:
    PNGImagen pngImagen;

public:
    void mostrar() {
        pngImagen.mostrarPNG();
    }
};

int main() {
    // Crear instancia del Adapter para formato PNG
    AdapterPNG adapterPNG;
    adapterPNG.mostrar();  // Podemos utilizar la misma interfaz que JPEGImagen!

    return 0;
}
