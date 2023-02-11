#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct arista{
    char inicio;
    char fin;
    int peso;
    arista(int _inicio, int _fin, int _peso){
        inicio = _inicio;
        fin = _fin;
        peso = _peso;
    }
};
 
class Grafo{
    private:
        vector<arista> aristas;
        vector<arista> visitados;
    
    public:
        void insertar_arista(char _inicio, char _fin, int _peso){
            aristas.push_back(arista(_inicio, _fin, _peso));
        }
        void print(){
            for_each(aristas.begin(), aristas.end(), 
                [](arista a){
                    cout << a.inicio << " - " 
                         << a.fin << ": " 
                         << a.peso << endl;});
        }
};

int main(){
    Grafo G;
    G.insertar_arista('A','C',4);
    G.insertar_arista('A','D',7);
    G.insertar_arista('C','D',11);
    G.insertar_arista('C','E',20);
    G.insertar_arista('C','F',9 );
    G.insertar_arista('D','E',1);
    G.insertar_arista('F','G',2);
    G.insertar_arista('E','G',1);
    G.insertar_arista('E','I',3);
    G.insertar_arista('F','H',6);
    G.insertar_arista('G','H',10);
    G.insertar_arista('G','B',15);
    G.insertar_arista('G','I',5);
    G.insertar_arista('H','B',5);
    G.insertar_arista('I','B',12);
    G.print();

    return 0;
}