#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct Grafo{
    map<char,set<char>> g_map;
    set<char> visitados;

    void nueva_arista(char v1, char v2);
    void BFS(char u);
};

void Grafo::nueva_arista(char v1, char v2){
    g_map[v1].insert(v2);
    g_map[v2].insert(v1);
}


void Grafo::BFS(char u){
    visitados.insert(u);
    queue<char> Q;
    Q.push(u);

    while (Q.size() != 0){
        char v = Q.front();
        cout << "Visitando -> " << v << endl;
        Q.pop();
        for (const char& e: g_map[v]){
            if (visitados.find(e) == visitados.end()){
                Q.push(e);
                visitados.insert(e);
            }
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

    g.BFS('A');
}