#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

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
        vector<Arista> AEM; 

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
            if (padre[vertice1]==vertice1)
                padre[vertice1] = vertice2;
            else
                padre[vertice2] = vertice1;
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

        void kruskal(){
            char padre1, padre2;
            sort(G.begin(), G.end());
            for (auto it=G.begin(); it!=G.end(); it++){
                padre1 = encontrar_padre((*it).inicio);
                padre2 = encontrar_padre((*it).fin);

                if (padre1 != padre2){
                    AEM.push_back(*it);
                    unir((*it).inicio, (*it).fin);
                }
            }
        }

        void printAEM(){
            for (auto it=AEM.begin(); it!=AEM.end(); it++){
                cout << (*it).inicio << " - ";
                cout << (*it).fin << endl;
            }           
        }
};


int main(){
    Grafo G;
    G.insertar_arista('A','B',5);
    G.insertar_arista('A','C',7);
    G.insertar_arista('B','C',9);
    G.insertar_arista('B','E',15);
    G.insertar_arista('B','F',6);
    G.insertar_arista('C','D',8);
    G.insertar_arista('C','E',7);
    G.insertar_arista('D','E',5);
    G.insertar_arista('E','F',8);
    G.insertar_arista('E','G',9);
    G.insertar_arista('F','G',11);
    /*
    G.insertar_arista('A','B',5);
    G.insertar_arista('B','C',3);
    G.insertar_arista('B','E',2);
    G.insertar_arista('B','D',5);
    G.insertar_arista('C','E',1);
    G.insertar_arista('D','A',4);
    G.insertar_arista('D','E',2);
    G.insertar_arista('D','F',6);
    G.insertar_arista('E','F',4);
    G.insertar_arista('E','G',6);
    G.insertar_arista('F','G',2);
    */
    G.kruskal();
    G.printAEM();

    return 0;
}