/*
1. Implemente a programa that create characters of the world of warcraft game.
2. Each character should belong to a race: Elfo, Humano, Orco.
3. Each race should have a different way to attack and recover health.
    - Elfo: Ataque con arco y flecha. Recupera vida con magia.
    - Orco: Ataque con hacha. Recupera vida con carne.
    - Humano: Ataque con espada. Recupera vida con agua.
4. Use virtual functions and inheritance. 
5. Use pointer to a base class to use the methods of the derived classes.
*/

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
    Pj* pj1 = new Pj("Grim", "Orco", 100, 20);
    Pj* pj2 = new Pj("Legolas", "Elfo", 60, 35);
    Pj* pj3 = new Pj("Aragorn", "Humano", 80, 25);

    Carne carne;
    Agua agua;
    Magia magia;

    cout << *pj1 << *pj2 << *pj3;

    pj1->curar(carne);
    pj2->curar(magia);
    pj3->curar(agua);

    cout << *pj1 << *pj2 << *pj3;

    delete pj1, pj2, pj3;

    return 0;
}
    
