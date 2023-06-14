#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solicitud {
private:
    int id;
    string descripcion;

public:
    Solicitud(int _id, const string& _descripcion) : id(_id), descripcion(_descripcion) {}

    int getId() const {
        return id;
    }

    string getDescripcion() const {
        return descripcion;
    }
};

class Servidor {
private:
    queue<Solicitud> solicitudes;

public:
    void agregarSolicitud(const Solicitud& solicitud) {
        solicitudes.push(solicitud);
        cout << "Solicitud agregada - ID: " << solicitud.getId() << endl;
    }

    void procesarSolicitudes() {
        cout << "Procesando solicitudes..." << endl;

        while (!solicitudes.empty()) {
            Solicitud solicitudActual = solicitudes.front();
            solicitudes.pop();
            cout << "Solicitud procesada - ID: " << solicitudActual.getId() << ", Descripcion: " << solicitudActual.getDescripcion() << endl;
        }
    }
};

int main() {
    Servidor servidor;

    Solicitud solicitud1(212, "Solicitud de acceso al sistema");
    Solicitud solicitud2(103, "Solicitud de actualizacion de datos");
    Solicitud solicitud3(111, "Solicitud de generacion de reporte");

    servidor.agregarSolicitud(solicitud1); // Salida: Solicitud agregada - ID: 212
    servidor.agregarSolicitud(solicitud2); // Salida: Solicitud agregada - ID: 103 
    servidor.agregarSolicitud(solicitud3); // Salida: Solicitud agregada - ID: 111

    servidor.procesarSolicitudes(); 
    // Salida:
    // Procesando solicitudes...
    // Solicitud procesada - ID: 212, Descripcion: Solicitud de acceso al sistema
    // Solicitud procesada - ID: 103, Descripcion: Solicitud de actualizacion de datos
    // Solicitud procesada - ID: 111, Descripcion: Solicitud de generacion de reporte

    return 0;
}
