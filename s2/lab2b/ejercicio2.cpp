#include <iostream>

using namespace std;

struct Item{
    int danio;
    virtual void usar() = 0;
};

struct Hacha: public Item{
    Hacha(): Item(){this->danio = 10;};
    void usar(){cout << "Hacha (-10)" << endl;};
};

struct Espada: public Item{
    Espada(): Item(){this->danio = 15;};
    void usar(){cout << "Espada (-15)" << endl;};
};

struct Arco: public Item{
    Arco(): Item(){this->danio = 20;};
    void usar(){cout << "Arco (-20)" << endl;};
};

class Pj{
friend ostream& operator<<(ostream& os, const Pj& pj);
private:
    string nombre;
    string raza;
    int vida;
    int ataque;
public:
    Pj(string n, string r, int v, int a): nombre(n), raza(r), vida(v), ataque(a){};
    void atacar(Item& item, Pj& pj);
};

ostream& operator<<(ostream& os, const Pj& pj){
    os << "----------------------------------------" << endl;
    os << "Nombre: " << pj.nombre << endl;
    os << "Raza: " << pj.raza << endl;
    os << "Vida: " << pj.vida << endl;
    os << "Ataque: " << pj.ataque << endl;
    os << "----------------------------------------" << endl;
    return os;
}

void Pj::atacar(Item& item, Pj& pj){
    cout << "----------------------------------------" << endl;
    cout << this->nombre << " ataca con ";
    item.usar();
    cout << "a " << pj.nombre << endl;
    cout << pj.nombre << " pierde " << item.danio << " puntos de vida" << endl;
    cout << "----------------------------------------" << endl;
    pj.vida -= item.danio;
}

int main(){
    Pj pj1("Orgrim", "Orco", 100, 20);
    Pj pj2("Legolas", "Elfo", 60, 35);
    Pj pj3("Aragorn", "Humano", 80, 25);
    
    Hacha hacha;
    Espada espada;
    Arco arco;
    
    cout << pj1 << pj2 << pj3;
    
    pj1.atacar(hacha, pj2);
    pj2.atacar(arco, pj3);

    cout << pj1 << pj2 << pj3;

    return 0;
}