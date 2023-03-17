#include <iostream>
#include <future>
#include <chrono>
#include <vector>

using namespace std;

int suma(vector<int> vec){
    int s = 0;
    for (int i=0; i<vec.size(); i++)
        s += vec[i];
    return s; 
}

void prod(promise<int>* obj, vector<int> vec){
    int p = 1;
    for (int i=0; i<vec.size(); i++)
        p *= vec[i];
    obj->set_value(p); 
}

int main(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;
    vector<int> vec(100000000,1);

    t_inicio = chrono::high_resolution_clock::now();
    promise<int> promise_obj;
    future<int> res = promise_obj.get_future();

    thread t1(prod, &promise_obj, vec);

    cout << "Respuesta f2 = " << suma(vec) << endl;
    cout << "Respuesta f1 = " << res.get() << endl;

    t_final  = chrono::high_resolution_clock::now(); 
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    t1.join();

    return 0;
}