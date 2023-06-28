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
    void BFS(T u, int depth);
};

template<typename T>
void Grafo<T>::nueva_arista(T v1, T v2){
    g_map[v1].insert(v2);
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
void Grafo<T>::BFS(T u, int depth){
    queue<T> Q;
    Q.push(u);  
    unordered_map<T,int> dist;
    dist[u] = 0;
    while (Q.size() != 0){
        T w = Q.front();
        Q.pop();
        if (visitados.find(w) == visitados.end() && dist[w] <= depth){
            visitados.insert(w);
            cout << "Explorando -> " << w << endl;
            for (const T& e: g_map[w]){
                if (visitados.find(e) == visitados.end()){
                    Q.push(e); 
                    dist[e] = dist[w] + 1;
                }
            }
        }
    }
}

int main(){
    Grafo<string> g;
    g.nueva_arista("http://www.google.com","http://www.google.com/finance");
    g.nueva_arista("http://www.google.com","http://www.google.com/maps");
    g.nueva_arista("http://www.google.com","http://www.google.com/translate");
    g.nueva_arista("http://www.google.com","http://www.facebook.com");
    g.nueva_arista("http://www.facebook.com","http://www.facebook.com/MarkZuckerberg");
    g.nueva_arista("http://www.facebook.com/MarkZuckerberg","http://www.facebook.com/MarkZuckerberg/photos");
    g.nueva_arista("http://www.google.com","http://www.twitter.com");
    g.nueva_arista("http://www.twitter.com","http://www.twitter.com/ElonMusk");
    g.nueva_arista("http://www.twitter.com/ElonMusk","http://www.twitter.com/ElonMusk/last_tweet");
    g.nueva_arista("http://www.google.com","http://www.youtube.com");
    g.nueva_arista("http://www.google.com","http://utec.edu.pe");

    g.BFS("http://www.google.com", 3);
}