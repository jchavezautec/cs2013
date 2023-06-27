#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T>
struct Grafo{
    unordered_map<T,unordered_set<T>> g_map;
    unordered_set<T> visitados;

    void nueva_arista(T v1, T v2);
    void DFS(T u);
    bool ciclosDFS(T u, T padre);
};

template<typename T>
void Grafo<T>::nueva_arista(T v1, T v2){
    g_map[v1].insert(v2);
    g_map[v2].insert(v1);
}

template<typename T>
void Grafo<T>::DFS(T u){
    if (visitados.find(u) != visitados.end())
        return;
    visitados.insert(u);
    cout << "Visitando -> " << u << endl;
    for(const T& next: g_map[u]){
        DFS(next);
    }
}

template<typename T>
bool Grafo<T>::ciclosDFS(T u, T padre){
    cout << "Visitando -> " << u << endl;
    visitados.insert(u);
    for(const T& next: g_map[u]){
        if (visitados.find(next) == visitados.end()){
            if (ciclosDFS(next,u))
                return true;
        }
        else if (next != padre){
            cout << "Ciclo encontrado en " << u << endl;
            return true;
        }
    }
    return false;
}
int main(){
    Grafo<char> g;
    g.nueva_arista('A','B');
    g.nueva_arista('A','C');
    g.nueva_arista('B','D');
    g.nueva_arista('C','E');
    g.nueva_arista('F','B');
    g.nueva_arista('F','D');

    //g.DFS('A');
    if (g.ciclosDFS('A','A'))   // ciclosDFS(nodo, padre)
        cout << "Hay ciclos" << endl;
    else
        cout << "No hay ciclos" << endl;
}