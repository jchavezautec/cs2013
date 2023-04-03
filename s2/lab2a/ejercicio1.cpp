#include <iostream>

using namespace std;

class Pj{
friend ostream& operator<<(ostream& os, const Pj& pj);
private:
    string nombre;
    string raza;
    int vida;
    int ataque;
public:
    Pj(string n, string r, int v, int a): nombre(n), raza(r), vida(v), ataque(a){};
    void operator+(int vida);
    void operator>>(Pj& pj);
};

ostream& operator<<(ostream& os, const Pj& pj){
    os << "----------------------------------------" << endl;
    os << "Nombre: " << pj.nombre << endl;
    os << "Vida: " << pj.vida << endl;
    os << "Ataque: " << pj.ataque << endl;
    os << "----------------------------------------" << endl;
    return os;
}

void Pj::operator>>(Pj& pj){
    cout << "----------------------------------------" << endl;
    cout << this->nombre << " ataca a " << pj.nombre << endl;
    cout << this->nombre << " hace " << this->ataque << " de danio" << endl;
    cout << "----------------------------------------" << endl;
    pj.vida -= this->ataque;
}

void Pj::operator+(int vida){
    cout << "----------------------------------------" << endl;
    cout << this->nombre << " recupera " << vida << " de vida" << endl;
    cout << "----------------------------------------" << endl;
    this->vida += vida;
}

int main(){
    // Crear personajes
    Pj orco("Grim", "Orco", 100, 20);
    Pj humano("Arthas", "Humano", 80, 30);
    Pj elfo("Legolas", "Elfo", 60, 40);

    // Mostrar atributos de los personajes
    cout << orco << humano << elfo;

    // Ataque de orco a humano
    orco >> humano;

    // Ataque de humano a elfo
    humano >> elfo;

    // Mostrar atributos de los personajes
    cout << orco << humano << elfo;

    // Recuperar vida de elfo
    elfo + 10;

    // Mostrar atributos de los personajes
    cout << orco << humano << elfo;


    return 0;
}