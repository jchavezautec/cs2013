#include <iostream>
#include <random>
#include <forward_list>
#include <algorithm>

using namespace std;

void append(forward_list<int> &lista, int x){
    auto it = lista.begin();
    while (next(it) != lista.end())
        it++;
    lista.insert_after(it, x);
}

int main(){
    forward_list<int> lista;

    generate_n(front_inserter(lista), 10, [](){return rand()%10;});
    
    for_each(lista.begin(),lista.end(),[](int x){cout << x << " ";});
    cout << endl;

    append(lista, 10);
    for_each(lista.begin(),lista.end(),[](int x){cout << x << " ";});

    return 0;
}