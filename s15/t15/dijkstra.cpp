#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
struct Grafo{
    unordered_map<T, unordered_map<T, int>> g_map;
    unordered_map<T, int> distancias;
    priority_queue<pair<int, T>> no_visitados;

    void nueva_arista(T v1, T v2, int peso);
    void dijkstra(T u);
};

template <typename T>
void Grafo<T>::nueva_arista(T v1, T v2, int peso){
    g_map[v1][v2] = peso;
    g_map[v2][v1] = peso;
}

template <typename T>
void Grafo<T>::dijkstra(T u){
    for (const auto& e: g_map)              // Inicializar distancias
        distancias[e.first] = INT_MAX;
    distancias[u] = 0;

    no_visitados.push(pair<int, T>(0, u)); // Inicializar cola de prioridad
    while (no_visitados.size() != 0){      // Mientras haya nodos sin visitar 
        T v = no_visitados.top().second;
        no_visitados.pop();

        // Actualizar distancias
        for (const auto& e: g_map[v]){
            if (distancias[e.first] > distancias[v] + e.second){
                distancias[e.first] = distancias[v] + e.second;
                no_visitados.push(pair<int, T>(-distancias[e.first], e.first));
            }
        }
    }

    for (const auto& e: distancias)
        cout << e.first << " -> " << e.second << endl;
}

int main(){
    Grafo<char> g;
    g.nueva_arista('A','C', 4);
    g.nueva_arista('A','D', 7);
    g.nueva_arista('C','D', 11);
    g.nueva_arista('C','E', 20);
    g.nueva_arista('C','F', 9);
    g.nueva_arista('D','E', 1);
    g.nueva_arista('E','G', 1);
    g.nueva_arista('E','I', 3);
    g.nueva_arista('F','G', 2);
    g.nueva_arista('F','H', 6);
    g.nueva_arista('G','H', 10);
    g.nueva_arista('G','B', 15);
    g.nueva_arista('G','I', 5);
    g.nueva_arista('H','B', 5);
    g.nueva_arista('I','B', 12);

    g.dijkstra('A'); // Salida: A->0, B->22, C->4, D->7, E->8, F->11, G->9, H->17, I->11
}