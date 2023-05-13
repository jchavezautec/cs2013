#include <iostream>
#include <thread>

using namespace std;

template<class T>
void foo(T a, T& b){
    b = b + a;
}

int main(){
    float a=1.1, b=2.2;
    std::thread t(foo<float>, a, ref(b));    
    cout << "b = " << b << endl;
    
    t.join();           

    return 0;
}