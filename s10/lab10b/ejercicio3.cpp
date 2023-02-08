#include <iostream>
#include <chrono>
#include <math.h>
#include <vector>
#include <thread>

using namespace std;

bool es_primo(int n){
    if (n == 2)
        return true;
    for(int d = 2; d < n; d++){
        if (n % d == 0)
            return false;
    }
    return true;
}

void contar_primos_w_threads(int inicio, int fin, int& count){
    for(int i = inicio; i < fin; i++){
        if(es_primo(i)){
            count++;
        }
    }
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    
    vector<thread> vthreads;
    int n_threads = 4;
    int size = (pow(2,25)-2 + 1);
    int count[4] = {0,0,0,0};
    t_inicio = chrono::high_resolution_clock::now();
    
    for (int i=0; i < 4; i++){
        int inicio = 2 + i * size / 4;
        int fin    = 2 + (i + 1) * size / 4;
        vthreads.push_back(
            thread(&contar_primos_w_threads, inicio, fin, ref(count[i])));
    }

    for (int i=0; i < 4; i++){
        vthreads[i].join();
    }

    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    return 0;
}