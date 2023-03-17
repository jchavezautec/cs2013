#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}

template<typename T>
class Grafo{
    private:
        map<T,set<T>> g_mapa;
        set<T> visitados;
        map<T,pair<T,int>> dist;

        int _n;
        char** celdas;

    public:
        Grafo(int n): _n(n+2){};
        ~Grafo();

        void generar_grafo();
        void nueva_arista(T v1, T v2);
        void BFS(T u);

        // Generar y dibujar el camino
        void generar_camino(T inicio, T final);
        void dibujar_celdas();
};

template<typename T>
void Grafo<T>::generar_grafo(){
    // Generar la matriz de celdas, inicialmente
    // todas abiertas
    celdas = new char*[_n];
    for(int i=0; i < _n; i++){
        celdas[i] = new char[_n];
        for(int j=0; j < _n; j++){
            if (i == 0 || j == 0 || i == _n-1 || j == _n-1)
                celdas[i][j] = 'X';
            else
                celdas[i][j] = ' ';
        }
    } 

    // Obstaculos: Cerrar algunas celdas
    celdas[3][3] = 'X';
    celdas[4][3] = 'X';
    celdas[5][3] = 'X';
    celdas[5][4] = 'X';
    celdas[5][5] = 'X';
    celdas[2][3] = '*'; // Inicio
    celdas[6][5] = '*'; // Fin

    // Generandos los nodos
    for(int i=0; i < _n; i++){
        for(int j=0; j < _n; j++){
            if (celdas[i][j] == 'X')
                continue;
            T p0 = make_pair(i,j);
            if (celdas[min(i+1,_n-1)][j] != 'X')
                nueva_arista(p0,make_pair(min(i+1,_n-1),j));
            if (celdas[i][min(j+1,_n-1)] != 'X')
                nueva_arista(p0,make_pair(min(i+1,_n-1),j));
            
            if (celdas[max(i-1,0)][j] != 'X')
                nueva_arista(p0,make_pair(max(i-1,0),j));
            if (celdas[i][max(j-1,0)] != 'X')
                nueva_arista(p0,make_pair(i,max(j-1,0))); 
        }
    }  
}

template<typename T>
Grafo<T>::~Grafo(){
    for(int i=0; i<_n; i++)
        delete[] celdas[i];
    delete[] celdas;
}

template<typename T>
void Grafo<T>::nueva_arista(T v1, T v2){
    // Creando la arista v1--v2
    g_mapa[v1].insert(v2);
    g_mapa[v2].insert(v1);
    dist[v1].second = _n * _n;
    dist[v2].second = _n * _n;
}

template<typename T>
void Grafo<T>::BFS(T u){
    dist[u].second = 0;
    visitados.insert(u);
    queue<T> Q;
    Q.push(u);

    while (Q.size() != 0){
        T v = Q.front();
        Q.pop();
        for (const T& e: g_mapa[v]){
            if (visitados.find(e) == visitados.end()){
                Q.push(e);
                visitados.insert(e);

                // El camino menos costoso para llegar al  nodo 'e'
                if (dist[v].second + 1 < dist[e].second){
                    dist[e].first = v;    // v es predecesor de e
                    dist[e].second = dist[v].second + 1;
                }

            }
        }
    }
}

template<typename T>
void Grafo<T>::generar_camino(T inicio, T final){
    if (inicio != final){
        generar_camino(inicio, dist[final].first);
        celdas[final.first][final.second] = '*';
    }
}

template<typename T>
void Grafo<T>::dibujar_celdas(){
    for(int i=0; i < _n; i++){
        for(int j=0; j < _n; j++)
            cout << celdas[i][j];
        cout << endl;
    }
    cout<<endl;
}

int main(){
    int n = 7;
    Grafo<pair<int,int>> g(n);
    g.generar_grafo();
    g.dibujar_celdas();

    pair<int,int> inicio(2,3);
    pair<int,int> final(6,5);
    
    g.BFS(inicio);
    g.generar_camino(inicio,final);
    g.dibujar_celdas();
}