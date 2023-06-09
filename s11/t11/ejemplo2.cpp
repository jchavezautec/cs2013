// DECORATOR

#include <iostream>
using namespace std;

// Interfaz para todos los informes
class Informe {
public:
    virtual void generar() = 0;
};

// Clase base para informes sin decorar
class InformeBase : public Informe {
public:
    void generar() {
        std::cout << "Generando informe base..." << std::endl;
    }
};

// Clase base para decoradores de informes
class InformeDecorador : public Informe {
protected:
    Informe* informe;

public:
    InformeDecorador(Informe* informe) : informe(informe) {}
    void generar() {
        informe->generar();
    }
};

// Decorador para añadir encabezado personalizado
class EncabezadoDecorador : public InformeDecorador {
private:
    std::string encabezado;

public:
    EncabezadoDecorador(Informe* informe, const std::string& encabezado) : InformeDecorador(informe), encabezado(encabezado) {}

    void generar() {
        std::cout << "Agregando encabezado personalizado: " << encabezado << std::endl;
        InformeDecorador::generar();
    }
};

int main() {
    // Crear un informe base
    InformeBase* informeBase = new InformeBase();
    informeBase->generar();

    // Crear un informe con encabezado personalizado
    EncabezadoDecorador* informeConEncabezado = new EncabezadoDecorador(informeBase, "Informe de Empleados");

    // Generar el informe final
    informeConEncabezado->generar();

    // Liberar la memoria
    delete informeConEncabezado;
    delete informeBase;

    return 0;
}