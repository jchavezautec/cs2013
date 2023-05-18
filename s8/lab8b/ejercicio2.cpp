#include <iostream>
#include <time.h>
#include <assert.h>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

void indentity(float** M, int dim){
    for (int i=0; i < dim; i++)
        M[i][i] = 1;
}

void random(float** M, int dim){
    for (int i=0; i < dim; i++)
        for (int j=0; j < dim; j++)
            M[i][j] = (float) rand() / RAND_MAX;
}

void multiply(float** M1, float** M2, float** M3, int dim){
    float s;
    for (int i=0; i < dim; i++)
        for (int j=0; j < dim; j++){
            s = 0.;
            for (int k=0; k<dim; k++)
                s += M1[i][k] * M2[k][j]; 
            M3[i][j] = s;
        }
}   

void multiply_with_threads(float** M1, float** M2, float** M3, int dim, int chunk, int chunks){
    int inicio = chunk * (dim/chunks);
    int fin = (chunk + 1) * (dim/chunks);
    float s;
    for (int i=inicio; i < fin; i++)
        for (int j=0; j < dim; j++){
            s = 0.;
            for (int k=0; k<dim; k++)
                s += M1[i][k] * M2[k][j]; 
            M3[i][j] = s;
        }
}   

void igualdad(float** M1, float** M2, int dim){
    for (int i=0; i < dim; i++)
        for (int j=0; j < dim; j++)
            assert(M1[i][j] == M2[i][j]);   
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    srand(time(NULL));
    int dim = 10;
    
    float** m1 = new float*[dim];
    float** m2 = new float*[dim];
    float** m3 = new float*[dim];

    for (int i=0; i < dim; i++){
        m1[i] = new float[dim];
        for (int j=0; j < dim; j++)
            m1[i][j] = 0;
    }

    for (int i=0; i < dim; i++){
        m2[i] = new float[dim];
    }

    for (int i=0; i < dim; i++){
        m3[i] = new float[dim];
    }

    indentity(m1, dim);
    random(m2, dim);

    int n_threads = thread::hardware_concurrency()/2;
    vector<thread> vthreads;

    t_inicio = chrono::high_resolution_clock::now();

    //multiply(m1,m2,m3,dim);
    for (int i=0; i < n_threads; i++)
        vthreads.push_back(thread(&multiply_with_threads,m1,m2,m3,dim,i,n_threads));
    
    for (int i=0; i < n_threads; i++)
        vthreads[i].join();

    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    igualdad(m2,m3,dim);

    for (int i=0; i < dim; i++)
       delete[] m1[i];
    delete[] m1;

    for (int i=0; i < dim; i++)
       delete[] m2[i];
    delete[] m2;

    for (int i=0; i < dim; i++)
       delete[] m3[i];
    delete[] m3;

}