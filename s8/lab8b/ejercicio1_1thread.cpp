#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <assert.h>

using namespace std;

void sumar(vector<int> A, vector<int> B, vector<int>& C){
    for (int i=0; i < A.size(); i++)
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
    
    sumar(A,B,C);

    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;
    
    verificarSuma(C);
               
    return 0;
}
