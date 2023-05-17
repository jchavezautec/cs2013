/*
Implement an program that uses two threads.

1. One thread will generate numbers from 1 to 100 and store them in a vector.
2. The other thread will compute the mean of the numbers in the vector.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <thread>

using namespace std;

void generar_numeros(vector<int> &v) {
    for (int i = 1; i <= 1000000; i++) {
        int num = rand() % 100 + 1;
        v.push_back(num);
    }
}


int main() {
    vector<int> v;
    double mean;

    thread t1(generar_numeros, ref(v));

    t1.detach();

    this_thread::sleep_for(chrono::milliseconds(10));
    double sum = 0.0;
    int size = 0;
    cout << v.size() << endl;
    while (!v.empty()) {    
        sum += v.back();
        v.pop_back();
    }
    cout << "Mean: " << sum / 1000000 << endl;
    return 0;
}
