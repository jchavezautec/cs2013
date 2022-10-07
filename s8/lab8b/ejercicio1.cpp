#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <assert.h>

using namespace std;

void sumar(vector<int> A, vector<int> B, vector<int>& C, int chunk, int chunks){
    int inicio = chunk * (A.size()/chunks);
    int fin = (chunk + 1) * (A.size()/chunks);

    for (int i=inicio; i < fin; i++)
        C[i] = A[i] + B[i];
}   

void verificarSuma(vector<int> C){
    for (const int e: C)
        assert(e == 3);
}
int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<int> A(100000000, 1);
    vector<int> B(100000000, 2);
    vector<int> C(100000000);

    t_inicio = chrono::high_resolution_clock::now();
    
    thread t1(&sumar, A, B, ref(C), 0,2);
    thread t2(&sumar, A, B, ref(C), 1,2);

    t1.join();
    t2.join();

    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    
    verificarSuma(C);
               
    return 0;
}

