#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Arista{
    char inicio;
    char fin;
    int peso;
    Arista(char _inicio, char _fin, int _peso){
        inicio = _inicio;
        fin = _fin;
        peso = _peso;
    }
    bool operator<(const Arista& arista) const{
        return peso < arista.peso;
    }   
};

class Grafo{
    private:
        vector<Arista> G;
        map<char, char> padre;    
    public:
        void insertar_arista(char inicio, char fin, int peso){
            G.push_back(Arista(inicio,fin,peso));
            padre[inicio] = inicio;
            padre[fin] = fin;
        }
        char encontrar_padre(char vertice){
            if (vertice == padre[vertice])
                return vertice;
            else
                return encontrar_padre(padre[vertice]);
        }
        void unir(char vertice1, char vertice2){
            if (encontrar_padre(vertice1) == encontrar_padre(vertice2))
                cout << "Se formará un bucle" << endl;
            else{
                if (padre[vertice1]==vertice1)
                    padre[vertice1] = padre[vertice2];
                else
                    padre[vertice2] = padre[vertice1];
            }
        }
        void mostrar_padres(){
            cout << "Vertices: ";
            for(auto it=padre.begin();it!=padre.end(); it++)
                cout << (*it).first << " ";
            cout<<endl;   
            cout << "Padres  : ";  
            for(auto it=padre.begin();it!=padre.end(); it++)
                cout << encontrar_padre((*it).first) << " ";
            cout<<endl; 
        }
};

int main(){
    Grafo G;
    G.insertar_arista('A','B',5);
    G.insertar_arista('B','C',3);

    G.mostrar_padres();
    cout << "Uniendo A y B" << endl;
    G.unir('A','B');
    G.mostrar_padres();
    
    cout << "Uniendo B y C" << endl;
    G.unir('B','C');
    G.mostrar_padres();

    cout << "Uniendo A y C" << endl;
    G.unir('A','C');

    return 0;
}