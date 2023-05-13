#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex m;
void add(vector<int>& A, int e){
    m.lock();
    for (int i=0; i < 10; i++)
        A.push_back(e);
    m.unlock();
}

int main(){
    vector<int> A;
    thread t1(&add, ref(A), 1);
    thread t2(&add, ref(A), 2);

    t1.join();
    t2.join();

    cout << A.size() << endl;

    for (const int e: A)
        cout << e << " ";
    cout << endl;
    
    return 0;
}