#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int f1(){
    int s = 0;
    for (int i=0; i<100000000; i++)
        s += 1;
    return s; 
}

int f2(){
    int s = 0;
    for (int i=0; i<200000000; i++)
        s += 1;
    return s; 
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    t_inicio = chrono::high_resolution_clock::now();

    future<int> res = async(&f1);

    cout << "Respuesta f2 = " << f2() << endl;
    cout << "Respuesta f1 = " << f1() << endl;

    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    return 0;
}