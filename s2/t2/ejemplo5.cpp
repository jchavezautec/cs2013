#include <iostream>

using namespace std;

#include <iostream>
using namespace std;
 


class Forma{
public:
    virtual void dibujar() {cout << "Forma" << endl;}
};

class Circulo: public Forma{
public:
    void dibujar() { cout << "Circulo" << endl; }
};

class Triangulo: public Forma{
public:
    void dibujar() { cout << "Triangulo" << endl; }
};

int main(){
    Forma *f;
    Circulo c;
    Triangulo t;
    
    f = &c;
    f->dibujar();
    f = &t;
    f->dibujar();
    
    return 0;
}