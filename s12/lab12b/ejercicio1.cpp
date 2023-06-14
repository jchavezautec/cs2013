#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

class Banco {
private:
    queue<string> filaClientes;
public:
    void agregarCliente(const string& cliente) {
        filaClientes.push(cliente);
        cout << "Cliente '" << cliente << "' agregado." << endl;
    }

    void atenderCliente() {
        if (filaClientes.empty()) {
            cout << "No hay clientes en espera." << endl;
        } else {
            string cliente = filaClientes.front();
            filaClientes.pop();
            cout << "Atendiendo: " << cliente << endl;
        }
    }

    void mostrarClientesEnEspera() {
        queue<string> tmp = filaClientes;
        int turno = 1;
        cout << "Clientes en espera: ";
        while (!tmp.empty()) {
            cout << turno++ << ". ";
            cout << tmp.front() << " ";
            tmp.pop();
        }
        cout << endl;
    }
};

int main() {
    Banco banco;

    banco.agregarCliente("Juan");
    banco.agregarCliente("Maria");
    banco.agregarCliente("Pedro");
    banco.mostrarClientesEnEspera(); // 1. Juan 2. Maria 3. Pedro
    banco.atenderCliente();
    banco.mostrarClientesEnEspera(); // 1. Maria 2. Pedro
    banco.atenderCliente();
    banco.atenderCliente();
    banco.mostrarClientesEnEspera(); // No hay clientes en espera.

    return 0;
}
