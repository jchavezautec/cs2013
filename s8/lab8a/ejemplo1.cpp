#include <iostream>
#include <thread>

void foo(){
    std::cout << "funcion 'foo'\n";
}   

int main(){
    std::thread t(&foo);    
    t.join();           
               
    return 0;
}



