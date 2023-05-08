#include <iostream>
#include <random>
#include <forward_list>
#include <algorithm>
#include <set>
#include <unordered_set>

using namespace std;

template<class T>
class printContainer{
private:
    char _end;
public:
    printContainer(char c = ' '): _end(c) {}
    void operator() (T x){
        cout << x << _end;
    }
};

bool es_compuesto(int x){
    if (x < 2)
        return true;
    for (int i=2; i < x; i++){
        if (x % i == 0)
            return true;
    }
    return false;
}

int main(){
    forward_list<int> lista;

    generate_n(front_inserter(lista), 100, [](){return rand()%21;});

    cout << "Numeros:"<<endl;
    for_each(lista.begin(),lista.end(),printContainer<int>());
    cout << endl;

    lista.remove_if(es_compuesto);
    cout << "\nPrimos repetidos:"<<endl;
    for_each(lista.begin(),lista.end(),printContainer<int>());
    cout << endl;


    cout << "\nPrimos:" << endl;

    //set<int> s(lista.begin(), lista.end());
    unordered_set<int> s(lista.begin(), lista.end());
    for_each(s.begin(),s.end(),printContainer<int>());
    cout << endl;

    return 0;
}