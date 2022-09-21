#include <iostream>
#include <random>
#include <forward_list>
#include <algorithm>

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

void foo(forward_list<string>& lista, string s1, string s2){
    auto it = find(lista.begin(), lista.end(), s1);

    if (it != lista.end()){
        lista.insert_after(it, s2);
    }
    else{
        auto it_prev = lista.before_begin();
        for (string e: lista)
            it_prev++;
        lista.insert_after(it_prev, s2);    
    }
}

int main(){
    forward_list<string> lista = {"Hola", "Mundo","en", "C++"};

    string s1 = "en";
    string s2 = "Python y";

    foo(lista, s1, s2);
    for_each(lista.begin(),lista.end(),printContainer<string>());
    cout << endl;

    foo(lista, "in", "...");
    for_each(lista.begin(),lista.end(),printContainer<string>());
    cout << endl;
    return 0;
}