#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <mutex>
#include <assert.h>

using namespace std;

mutex mtx;

void suma(vector<int> A, int& s, int chunk, int chunks){
    int inicio = chunk * (A.size()/chunks);
    int fin = (chunk + 1) * (A.size()/chunks);
    int s_ = 0;
     
    for (int i=inicio; i < fin; i++)
        s_ += A[i];

    mtx.lock();
    s = s + s_;
    mtx.unlock();

}   

void suma_(vector<int> A, int& s){
    for (int i=0; i < A.size(); i++)
        s += A[i];    
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    int N = 10000000;

    vector<int> A(N, 1.);

    vector<thread> vthreads;
    int n_threads = 2;

    //generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    //generate(B.begin(), B.end(), [](){return (double)rand()/RAND_MAX;});

    t_inicio = chrono::high_resolution_clock::now();
    
    int res=0;
    for (int i=0; i < n_threads; i++)
        vthreads.push_back(thread(&suma,A,ref(res),i,n_threads));
    
    for (int i=0; i < n_threads; i++)
        vthreads[i].join();
    //suma_(A,res);
    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    cout << "suma_elementos(A) = " << res << endl;
    assert(res == N);

    return 0;
}

