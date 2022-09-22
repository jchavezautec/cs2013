#include <iostream>
#include <random>
#include <forward_list>
#include <algorithm>
#include <set>

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
    for (int i=2; i < x; i++){
        if (x % i == 0)
            return true;
    }
    return false;
}

int main(){
    forward_list<int> lista;

    for (int i = 0; i < 100; i++){
        lista.push_front(rand()%100);
    }
    cout << "numeros:"<<endl;
    for_each(lista.begin(),lista.end(),printContainer<int>());
    cout << endl;

    lista.remove_if(es_compuesto);
    cout << "\nprimos repetidos:"<<endl;
    for_each(lista.begin(),lista.end(),printContainer<int>());
    cout << endl;


    cout << "\nprimos:" << endl;
    set<int> s(lista.begin(), lista.end());
    for_each(s.begin(),s.end(),printContainer<int>());
    cout << endl;

    return 0;
}