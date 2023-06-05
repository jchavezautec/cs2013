#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Interfaz del objeto de sitio web
class SitioWeb {
public:
    virtual void cargar() const = 0;
};

// Implementación concreta del objeto de sitio web
class SitioWebReal : public SitioWeb {
private:
    string url;
    void cargarDesdeServidor() {
        // Lógica para cargar el sitio web desde el servidor
        cout << "Descargando el sitio web desde el servidor: " << url << endl;
    }
public:
    SitioWebReal(const string& url) : url(url) {
        // Cargar el sitio web desde el servidor
        cargarDesdeServidor();
    }

    void cargar() const override {
        // Lógica para cargar el sitio web
        cout << "Cargando el sitio web: " << url << endl;
    }

    string getUrl() const {
        return url;
    }
};

// Proxy del objeto de sitio web
class ProxySitioWeb : public SitioWeb {
private:
    SitioWebReal* sitioWebReal;
    vector<string> sitiosWebNoPermitidos = {
        "www.sitioprohibido1.com",
        "www.sitioprohibido2.com",
        "www.sitioprohibido3.com"
    };

public:
    ProxySitioWeb(const string& url) {
        sitioWebReal = new SitioWebReal(url);
    }

    void cargar() const override {
        // Verificar si el sitio web es permitido
        if (esSitioWebPermitido()) {
            sitioWebReal->cargar();
        } else {
            cout << "Acceso a sitio web no permitido" << endl;
        }
    }

private:
    bool esSitioWebPermitido() const {
        // Lógica para verificar si el sitio web es permitido
        string url = sitioWebReal->getUrl();
        for (const string& sitioWeb : sitiosWebNoPermitidos) {
            if (url.find(sitioWeb) != string::npos) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    // Crear el proxy de acceso al sitio web
    ProxySitioWeb sitio1("www.sitiopermitido.com");

    // Utilizar el proxy para cargar el sitio web
    sitio1.cargar();

    // Crear el proxy de acceso al sitio web
    ProxySitioWeb sitio2("www.sitioprohibido1.com");

    // Utilizar el proxy para cargar el sitio web
    sitio2.cargar();

    return 0;
}
