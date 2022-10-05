#include <iostream>
#include <thread>

using namespace std;

void foo(int a, int& b){
    b = b + a;
}

int main(){
    int a=1, b=2;
    std::thread t(foo, a, ref(b));    
    cout << "b = " << b << endl;
    
    t.join();           

    return 0;
}