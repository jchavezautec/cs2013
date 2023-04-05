#include <iostream>

using namespace std;

struct Item{
    int vida;
    virtual void usar() = 0;
};

struct Carne: public Item{
    Carne(): Item(){this->vida = 10;};
    void usar(){cout << "Carne (+10)" << endl;};
};

struct Agua: public Item{
    Agua(): Item(){this->vida = 5;};
    void usar(){cout << "Agua (+5)" << endl;};
};

struct Magia: public Item{
    Magia(): Item(){this->vida = 8;};
    void usar(){cout << "Magia (+8)" << endl;};
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
    void operator+(Item& item);
    void operator>>(Pj& pj);
    void curar(Item& item);
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

void Pj::curar(Item& item){
    cout << "----------------------------------------" << endl;
    cout << this->nombre << " se cura con ";
    item.usar();
    cout << "----------------------------------------" << endl;
    this->vida += item.vida;
}

int main(){
    Pj pj1("Orgrim", "Orco", 100, 20);
    Pj pj2("Legolas", "Elfo", 60, 35);
    Pj pj3("Aragorn", "Humano", 80, 25);

    Carne carne;
    Agua agua;
    Magia magia;

    cout << pj1 << pj2 << pj3;

    pj1.curar(carne);
    pj2.curar(magia);
    pj3.curar(agua);

    cout << pj1 << pj2 << pj3;

    return 0;
}
    
