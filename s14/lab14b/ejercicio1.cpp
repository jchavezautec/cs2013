#include <iostream>
#include <vector>
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

int main(){
    vector<Arista> aristas;
    aristas.push_back(Arista('A','B',5));
    aristas.push_back(Arista('B','C',3));
    aristas.push_back(Arista('B','E',2));
    aristas.push_back(Arista('B','D',5));
    aristas.push_back(Arista('C','E',1));
    aristas.push_back(Arista('D','A',5));
    aristas.push_back(Arista('D','E',2));
    aristas.push_back(Arista('D','F',6));
    aristas.push_back(Arista('E','F',4));
    aristas.push_back(Arista('E','G',6));
    aristas.push_back(Arista('F','G',2));

    sort(aristas.begin(), aristas.end());
    for_each(aristas.begin(), aristas.end(), [](Arista a){cout << a.peso << endl;});
    
    return 0;
}