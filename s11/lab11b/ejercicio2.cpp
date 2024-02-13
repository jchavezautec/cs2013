#include <iostream>
#include <vector>

using namespace std;

class Memento {
private:
    int Nivel;
    int posicionX;
    int posicionY;

public:
  Memento(const int& Nivel_, int posicionX, int posicionY)
        : Nivel(Nivel_), posicionX(posicionX), posicionY(posicionY) {}

    int getNombreNivel() const { return Nivel;}
    int getPosicionX() const { return posicionX;}
    int getPosicionY() const { return posicionY;}
};


class Personaje{
private:
  string nombre;
  int nivel=1;
  int x=0, y=0;
  vector<Memento*> estados;
public:
  Personaje(string n): nombre(n){}
  void info(){
    cout << "Nivel: " << nivel << ", Pos=(";
    cout << x << ", " << y << ")"<< endl;
  }
  void guardarEstado(){
    nivel = nivel + rand() % 4; // x puede crecer entre 0 y 3
    x = x + rand() % 3; // x puede crecer entre 0 y 2
    y = y + rand() % 3;  
    estados.push_back(new Memento(nivel,x,y));
  }
  void ver_estados(){
    for(int i=0; i<estados.size(); i++){
      cout << "-------------------------" << "(" << i + 1 << ")" << endl;
      cout << "Nivel: " << estados[i]->getNombreNivel() << endl;
      cout << "\tX: " << estados[i]->getPosicionX() << endl;
      cout << "\tY: " << estados[i]->getPosicionY() << endl;
    }
  }
  void setEstado(){
    ver_estados();
    int opcion;
    cout << "\nElegir Opción: ";
    cin >> opcion;
    Memento* memento = estados[opcion-1];
    nivel = memento->getNombreNivel();
    x = memento->getPosicionX();
    y = memento->getPosicionY();
  }
};

int main() {
  Personaje pj("Heroe");

  pj.guardarEstado();
  pj.guardarEstado();
  pj.guardarEstado();

  pj.setEstado();

  pj.info();
}
