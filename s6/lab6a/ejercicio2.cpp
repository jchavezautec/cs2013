#include <iostream>
#include <random>
#include <forward_list>
#include <algorithm>

using namespace std;

bool es_compuesto(int x){
    for (int i=2; i < x; i++){
        if (x % i == 0)
            return true;
    }
    return false;
}

int main(){
    forward_list<int> lista;
    // Metodo 1:
    for (int i=0; i<100; i++)
        lista.push_front(rand()%99 + 1);

    // Metodo 2:
    //generate_n(front_inserter(lista), 100, [](){return rand()%99 + 1;});

    for_each(lista.begin(),lista.end(),[](int x){cout << x << " ";});
    cout << endl;

    lista.remove_if(es_compuesto);
    for_each(lista.begin(),lista.end(),[](int x){cout << x << " ";});
    cout << endl;

    cout << "lista[size] = " << distance(lista.begin(), lista.end());
    cout << endl;

    return 0;
}