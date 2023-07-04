#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>

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
    int ancho, alto;
    vector<arista<T>> aristas;
    vector<arista<T>> MST;
    unordered_map<T, T> padres;
    unordered_map<T, int> rango;
    
    void nueva_arista(T, T, int);
    void generar_grafo(int, int);
    T ancestro(T);
    void kruskal();
    void imprimir_MST();
};

template <typename T>
void Grafo<T>::nueva_arista(T v1, T v2, int peso){
    aristas.emplace_back(arista<T>(v1, v2, peso));
    padres[v1] = v1;
    padres[v2] = v2;
    rango[v1] = 1;
    rango[v2] = 1;
}

template<typename T>
void Grafo<T>::generar_grafo(int n, int m){
    ancho = n;
    alto  = m;
    for(int i=0; i<alto; i++){
        for(int j=0; j<ancho; j++){
            if(j < ancho-1)
                nueva_arista(i*ancho+j, i*ancho+j+1,1);
            if(i < alto-1)
                nueva_arista(i*ancho+j, (i+1)*ancho+j,1);
        }
    }
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
    random_shuffle(aristas.begin(), aristas.end()); // Ordenar aristas por peso
    for (const auto& e: aristas){
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
    unordered_map<int,unordered_set<int>> laberinto;
    for (const auto& e: MST){
        laberinto[min(e.v1,e.v2)].insert(max(e.v1,e.v2));
        cout << min(e.v1,e.v2) << "---" << max(e.v1,e.v2) << endl;
    }
    string l1="+",l2;
    for (int j=0; j<ancho; j++)
        l1 += "---+";
    cout << l1 << endl;
    int x;
    for (int i=0; i<alto; i++){
        l1 = "|";
        l2 = "+";
        for (int j=0; j<ancho; j++){
            x = i*ancho+j;
            int vecinos = laberinto[x].size();
            if (vecinos == 0){
                l1 += "   |";
                l2 += "---+";
            }
            else if(vecinos == 2){
                l1 += "    ";
                l2 += "   +";
            }
            else{
                int v = *begin(laberinto[x]);
                if (v == x + 1){
                    l1 += "    ";
                    l2 += "---+";
                }
                else if (v == x + ancho){
                    l1 += "   |";
                    l2 += "   +";
                }
            }
        }
        cout << l1 << endl;
        cout << l2 << endl;
    }
}
int main(){
    Grafo<int> g;
    int n, m;
    cout << "n, m: ";
    cin >> n >> m;
    g.generar_grafo(n,m);
    g.kruskal();
    g.imprimir_MST();
}