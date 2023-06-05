#include <iostream>
#include <string>

using namespace std;

// Componente base
class Pedido {
public:
    virtual string obtenerDetalle() const = 0;
};

// Pedido base
class PedidoBase : public Pedido {
public:
    string obtenerDetalle() const override {
        return "Pedido base";
    }
};

// Decorador abstracto
class DecoradorPedido : public Pedido {
protected:
    Pedido* pedido;

public:
    DecoradorPedido(Pedido* pedido) : pedido(pedido) {}

    string obtenerDetalle() const override {
        return pedido->obtenerDetalle();
    }
};

// Decorador concreto: Envío urgente
class EnvioUrgente : public DecoradorPedido {
public:
    EnvioUrgente(Pedido* pedido) : DecoradorPedido(pedido) {}

    string obtenerDetalle() const override {
        return DecoradorPedido::obtenerDetalle() + " + Envio urgente";
    }
};

// Decorador concreto: Envío con regalo
class EnvioConRegalo : public DecoradorPedido {
public:
    EnvioConRegalo(Pedido* pedido) : DecoradorPedido(pedido) {}

    string obtenerDetalle() const override {
        return DecoradorPedido::obtenerDetalle() + " + Envio con regalo";
    }
};

int main() {
    // Crear el pedido base
    Pedido* pedidoBase = new PedidoBase();
    cout << pedidoBase->obtenerDetalle() << endl;

    // Agregar envío urgente al pedido base
    Pedido* pedidoUrgente = new EnvioUrgente(pedidoBase);
    cout << pedidoUrgente->obtenerDetalle() << endl;

    // Agregar envío con regalo al pedido base
    Pedido* pedidoConRegalo = new EnvioConRegalo(pedidoBase);
    cout << pedidoConRegalo->obtenerDetalle() << endl;

    // Agregar envío urgente y envío con regalo al pedido base
    Pedido* pedidoUrgenteConRegalo = new EnvioConRegalo(new EnvioUrgente(pedidoBase));
    cout << pedidoUrgenteConRegalo->obtenerDetalle() << endl;

    // Liberar la memoria
    delete pedidoUrgenteConRegalo;
    delete pedidoConRegalo;
    delete pedidoUrgente;
    delete pedidoBase;

    return 0;
}
