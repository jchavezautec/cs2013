#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

int f1(){
    int s = 0;
    for (int i=0; i<200000000; i++)
        s += 1;
    return s;
}

void foo(promise<int>* obj, int n){
    int sum = 0;
    for (int i=0; i<n; i++)
        sum += 1;
    obj->set_value(sum);
}

int main(){
    promise<int> promise_obj;
    future<int> fugure_obj = promise_obj.get_future();

    thread t1(foo, &promise_obj, 100000000);

    cout << "Respuesta f1  = " << f1() << endl;
    cout << "Respuesta foo = " <<fugure_obj.get() << endl;
    t1.join();
    return 0;
}