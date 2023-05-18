#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

using namespace std;

vector<int> stock;  // Vector de productos
mutex mtx;          // Mutex para sincronizar el acceso a stock

void produccion() {
    for (int i = 1; i <= 10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500));  // Simular algo de trabajo

        lock_guard<mutex> lock(mtx);    // Cerrar el mutex
        stock.push_back(i);             // Añadir un producto al stock

        cout << "Producido: " << i << endl;
    }
}

void consumidor() {
    for (int i = 1; i <= 10; ++i) {
        this_thread::sleep_for(chrono::milliseconds(800));  // Simular algo de trabajo

        lock_guard<mutex> lock(mtx);      // Cerrar el mutex
        if (!stock.empty()) {
            int data = stock.back();      // Obtener el último dato del stock
            stock.pop_back();            // Remover el último dato del stock

            cout << "Consumido: " << data << endl;
        }
    }
}

int main() {
    thread thread_produccion(produccion);
    thread thread_consumidor(consumidor);

    thread_produccion.join();
    thread_consumidor.join();

    return 0;
}
