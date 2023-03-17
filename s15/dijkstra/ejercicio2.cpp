#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <limits.h>

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
        vector<arista>  aristas;
        map<char, int>  dists;    
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

        void inicializar_dists(char origen){
            for (int i=0; i < aristas.size(); i++){
                dists[aristas[i].inicio] = INT_MAX;
                dists[aristas[i].fin]    = INT_MAX;
            }
            dists[origen] = 0;           
        }

        void print_dists(){
            for (auto it = dists.begin(); it!=dists.end(); it++){
                cout << (*it).first << ": " << (*it).second << endl;
            }
        }
        
        vector<pair<char,int>> get_vecinos(char vertice){
            vector<pair<char,int>> vecinos;
            for (auto it=aristas.begin(); it!=aristas.end(); it++){
                if ((*it).inicio == vertice){
                    vecinos.push_back(pair<char,int>((*it).fin, (*it).peso));
                } 
                else if((*it).fin == vertice){
                    vecinos.push_back(pair<char,int>((*it).inicio, (*it).peso));
                }
            }
            return vecinos;
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

    G.inicializar_dists('A');
    G.print_dists();
    cout << "\nVecinos:" << endl;
    vector<pair<char,int>> A_vecinos = G.get_vecinos('A');
    for(int i=0; i<A_vecinos.size(); i++){
        cout << "vecino " << A_vecinos[i].first;
        cout << "(peso=" << A_vecinos[i].second << ")" << endl;
    }
    return 0;
}