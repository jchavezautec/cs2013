#include <iostream>
#include <thread>

using namespace std;

void foo(){
    cout << "Funcion 'foo()'\n";
}

int main(){
    std::thread t(&foo);   
    cout << "Función 'main()'\n";
  
    t.detach();          

    return 0;
}
