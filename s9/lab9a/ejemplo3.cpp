#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex candado;

void add(int& s){
    candado.lock();
    ++s;
    candado.unlock();
}

int main(){
    int s = 0;
    thread t1(&add, ref(s));
    thread t2(&add, ref(s));

    t1.join();
    t2.join();

    cout << s << endl;

    return 0;
}