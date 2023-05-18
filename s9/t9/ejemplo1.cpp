#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;  // Variable global compartida
mutex mtx;        // Mutex para sincronizar el acceso a counter

void incrementar() {
    for (int i = 0; i < 100000; ++i) {
        //lock_guard<mutex> lock(mtx);  // Lock the mutex
        counter++;                    // Incrementar el contador de manera segura
    }
}

int main() {
    thread thread1(incrementar);
    thread thread2(incrementar);

    thread1.join();
    thread2.join();

    cout << "Contador: " << counter << endl;

    return 0;
}