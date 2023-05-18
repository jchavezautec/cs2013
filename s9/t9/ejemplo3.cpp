#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int counter = 0;  // Variable global compartida
mutex mtx;        // Mutex para sincronizar el acceso a counter

void incrementar() {
    int temp=0;
    for (int i = 0; i < 1000000; ++i) {
        temp++;                    // Incrementar el contador de manera segura
    }
    lock_guard<mutex> lock(mtx);  // Lock
    counter+=temp;
}

int main() {
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    
    t_inicio = chrono::system_clock::now();
    
    thread thread1(incrementar);
    thread thread2(incrementar);

    thread1.join();
    thread2.join();

    t_final = chrono::system_clock::now();

    cout << "Contador: " << counter << endl;
    chrono::duration<double, milli> elapsed_seconds = t_final - t_inicio;
    cout << "Tiempo de procesamiento: " << elapsed_seconds.count() << "ms" << endl;

    return 0;
}