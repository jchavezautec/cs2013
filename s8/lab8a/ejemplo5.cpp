#include <iostream>
#include <thread>

using namespace std;

void foo(){
    cout << "Iniciando foo()...\n";
    this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Finalizando foo()...\n";
}

int main(){
    std::thread t(&foo);    
    t.detach();   

    cout << "Iniciando Temporizandor de 1s...\n";  
    std::this_thread::sleep_for(std::chrono::seconds(1));      
    cout << "Finalizando Temporizador de 1s...\n";

    return 0;
}