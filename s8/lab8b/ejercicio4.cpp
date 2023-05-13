#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <assert.h>

using namespace std;

void sumar(vector<double> A, vector<double> B, double& s, int chunk, int chunks){
    int inicio = chunk * (A.size()/chunks);
    int fin = (chunk + 1) * (A.size()/chunks);

    for (int i=inicio; i < fin; i++)
        s += A[i] * B[i];
}   

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<double> A(100000000);
    vector<double> B(100000000);

    vector<thread> vthreads;
    int n_threads = thread::hardware_concurrency()/2;

    generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    generate(B.begin(), B.end(), [](){return (double)rand()/RAND_MAX;});

    t_inicio = chrono::high_resolution_clock::now();
    
    vector<double> outs(n_threads,0.);

    for (int i=0; i < n_threads; i++){
        vthreads.push_back(thread(&sumar, A, B, ref(outs[i]),i,n_threads));
    }

    
    for (int i=0; i < n_threads; i++){
        vthreads[i].join();
    }

    double res=0.;
    for (int i=0; i < n_threads; i++){
        res += outs[i];
    }
    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
               
    return 0;
}

