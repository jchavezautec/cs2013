#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

template<typename T>
struct Grafo{
    unordered_map<T,unordered_set<T>> g_map;
    unordered_set<T> visitados;

    void nueva_arista(T v1, T v2);
    void BFS(T u);
    int saltosBFS(T u, T v);
};

template<typename T>
void Grafo<T>::nueva_arista(T v1, T v2){
    g_map[v1].insert(v2);
    g_map[v2].insert(v1);
}

template<typename T>
void Grafo<T>::BFS(T u){
    queue<T> Q;
    Q.push(u);  

    while (Q.size() != 0){
        T v = Q.front();
        Q.pop();
        if (visitados.find(v) == visitados.end()){
            visitados.insert(v);
            cout << "Visitando -> " << v << endl;
            for (const T& e: g_map[v]){
                if (visitados.find(e) == visitados.end())
                    Q.push(e); 
            }
        }
    }
}

template<typename T>
int Grafo<T>::saltosBFS(T u, T v){
    queue<T> Q;
    Q.push(u);  
    unordered_map<T,int> dist;
    dist[u] = 0;
    while (Q.size() != 0){
        T w = Q.front();
        Q.pop();
        if (visitados.find(w) == visitados.end()){
            visitados.insert(w);
            for (const T& e: g_map[w]){
                if (visitados.find(e) == visitados.end()){
                    Q.push(e); 
                    dist[e] = dist[w] + 1;
                }
                if (e == v)
                    return dist[e];
            }
        }
    }
    return -1;
}
int main(){
    Grafo<char> g;
    g.nueva_arista('A','B'); // Grafo no dirigido
    g.nueva_arista('A','C'); // 
    g.nueva_arista('A','F'); // F ------- G
    g.nueva_arista('B','E'); // |         |
    g.nueva_arista('B','D'); // A -- B -- D
    g.nueva_arista('C','E'); // |    |
    g.nueva_arista('F','G'); // C -- E
    g.nueva_arista('G','D');

    cout << "Saltos: " << g.saltosBFS('A','D') << endl; // Salida: 2
}