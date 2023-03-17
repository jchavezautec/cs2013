#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Grafo{
    map<char,set<char>> g_map;
    set<char> visitados;

    void nueva_arista(char v1, char v2);
    void DFS(char u);
};

void Grafo::nueva_arista(char v1, char v2){
    g_map[v1].insert(v2);
    g_map[v2].insert(v1);
}


void Grafo::DFS(char u){
    visitados.insert(u);
    cout << "Visitando -> " << u << endl;
    for(const char& next: g_map[u]){
        if (visitados.find(next) == visitados.end()){
            DFS(next);
        }
    }
}

int main(){
    Grafo g;
    g.nueva_arista('A','B');
    g.nueva_arista('A','C');
    g.nueva_arista('B','C');
    g.nueva_arista('B','D');
    g.nueva_arista('C','E');

    g.DFS('A');
}