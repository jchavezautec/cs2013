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

// Clase para imágenes en formato PNG
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
    // Crear instancia de imagen en formato JPEG
    JPEGImagen imagenJPEG;
    PNGImagen imagenPNG;

    // Crear instancia del Adapter para formato PNG
    AdapterPNG adapterPNG;

    // Utilizar los métodos de IFormatoImagen para mostrar las imágenes
    imagenJPEG.mostrar();
    imagenPNG.mostrar();
    adapterPNG.mostrar();

    return 0;
}
