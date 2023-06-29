#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
struct arista{
    T v1, v2;
    int peso;
    arista(T _v1, T _v2, int _peso): v1(_v1), v2(_v2), peso(_peso) {}
    bool operator<(const arista& a) const{
        return peso < a.peso;
    }
};

template <typename T>
struct Grafo{
    vector<arista<T>> aristas;

    // El MST es un conjunto de aristas, un arbol no tiene ciclos.
    vector<arista<T>> MST;

    // El padre de un nodo es el nodo que lo contiene en el MST
    unordered_map<T, T> padres;

    // El rango de un nodo es la altura del arbol que se forma al unirlo
    unordered_map<T, int> rango;
    
    void nueva_arista(T v1, T v2, int peso);
    T ancestro(T v);
    void kruskal();
    void imprimir_MST();
};

template <typename T>
void Grafo<T>::nueva_arista(T v1, T v2, int peso){
    aristas.emplace_back(arista<T>(v1, v2, peso));
    padres[v1] = v1;
    padres[v2] = v2;
    rango[v1] = 0;
    rango[v2] = 0;
}

template <typename T>
T Grafo<T>::ancestro(T v){
    // Como el ancestro no tien padre, su padre es el mismo.
    // Cuando el padre de un nodo es el mismo, significa que
    // hemos llegado al ancestro.
    if (v == padres[v]) 
        return v;
    else
        return ancestro(padres[v]);
}

template <typename T>
void Grafo<T>::kruskal(){
    sort(aristas.begin(), aristas.end()); // Ordenar aristas por peso
    for (const auto& e: aristas){
        cout << "Arista: " << e.v1 << " --- " << e.v2 << endl;
        T ancestro1 = ancestro(e.v1);
        T ancestro2 = ancestro(e.v2);

        // La arista 'e' formara un ciclo si sus vertices tienen el mismo ancestro
        if (ancestro1 != ancestro2){                 
            MST.emplace_back(e);
            // Union por rango: El padre del ancestro con menor rango sera el ancestro
            //                  del otro nodo. Esto hace que el arbol este balanceado y
            //                  no crezca mucho en altura.
            if (rango[ancestro1] > rango[ancestro2])       
                padres[ancestro2] = ancestro1;
            else if (rango[ancestro1] < rango[ancestro2]) 
                padres[ancestro1] = ancestro2;
            else{
                padres[ancestro2] = ancestro1;
                rango[ancestro1]++;
            }
        }
    }
}

template <typename T>
void Grafo<T>::imprimir_MST(){
    for (const auto& e: MST)
        cout << e.v1 << " --- " << e.v2 << " (" << e.peso << ")" << endl;
}
int main(){
    Grafo<char> g;
    g.nueva_arista('A','B', 5);
    g.nueva_arista('A','C', 7);
    g.nueva_arista('B','C', 9);
    g.nueva_arista('B','E', 15);
    g.nueva_arista('B','F', 6);
    g.nueva_arista('C','D', 8);
    g.nueva_arista('C','E', 7);
    g.nueva_arista('D','E', 5);
    g.nueva_arista('E','F', 8);
    g.nueva_arista('E','G', 9);
    g.nueva_arista('F','G', 11);
    g.kruskal();
    g.imprimir_MST();
}