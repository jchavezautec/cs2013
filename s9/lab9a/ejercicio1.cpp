#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <mutex>
#include <assert.h>

using namespace std;

mutex mtx;

void dot(vector<double> A, vector<double> B, double& s, int chunk, int chunks){
    int inicio = chunk * (A.size()/chunks);
    int fin = (chunk + 1) * (A.size()/chunks);
    double s_ = 0;
     
    for (int i=inicio; i < fin; i++)
        s_ += A[i] * B[i];

    mtx.lock();
    s = s + s_;
    mtx.unlock();

}   

void dot_(vector<double> A, vector<double> B, double& s){
    for (int i=0; i < A.size(); i++)
        s += A[i] * B[i];    
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    int N = 10000000;

    vector<double> A(N, 1.);
    vector<double> B(N, 1.);

    vector<thread> vthreads;
    int n_threads = 2;

    //generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    //generate(B.begin(), B.end(), [](){return (double)rand()/RAND_MAX;});

    t_inicio = chrono::high_resolution_clock::now();
    
    double res=0.;
    for (int i=0; i < n_threads; i++)
        vthreads.push_back(thread(&dot,A,B,ref(res),i,n_threads));
    
    for (int i=0; i < n_threads; i++)
        vthreads[i].join();
    //dot_(A,B,res);
    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    cout << "<A . B> = " << res << endl;
    assert(res == N);

    return 0;
}

