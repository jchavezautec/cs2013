#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

// Saldo de la cuenta bancaria
int saldoCuenta = 1000;

// Mutex para sincronizar el acceso al saldo de la cuenta
mutex mutexCuenta;

// Función para simular una transacción bancaria
void transaccionBancaria(int monto) {
    // Adquirir el cerrojo (lock)
    mutexCuenta.lock();

    // Simular tiempo de procesamiento
    this_thread::sleep_for(chrono::milliseconds(500));

    // Realizar la transacción
    if (monto > 0) {
        cout << "Depositando S/." << monto << " en la cuenta." << endl;
        saldoCuenta += monto;
    } else {
        cout << "Retirando S/." << -monto << " de la cuenta." << endl;
        if (saldoCuenta >= -monto) {
            saldoCuenta += monto;
        } else {
            cout << "¡Fondos insuficientes! Transacción cancelada." << endl;
        }
    }

    // Imprimir el saldo actual de la cuenta
    cout << "Saldo actual de la cuenta: S/." << saldoCuenta << endl;

    // Liberar el cerrojo (unlock)
    mutexCuenta.unlock();
}

int main() {
    // Crear varios hilos para simular transacciones bancarias
    thread hilo1(transaccionBancaria, 500);     // Depositar 500 soles
    thread hilo2(transaccionBancaria, -300);    // Retirar 300 soles
    thread hilo3(transaccionBancaria, -800);    // Retirar 800 soles

    // Esperar a que todos los hilos finalicen
    hilo1.join();
    hilo2.join();
    hilo3.join();

    return 0;
}
