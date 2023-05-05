#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main(){
    vector<int> v(10);
    
    // Metodo 1:
    for (int i=0; i<10; i++)
        v[i] = rand()%100;
    
    // Metodo 2:
    //generate(v.begin(), v.end(), [](){return rand()%100;});
    
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << endl;

    // Encontrar el Maximo: Metodo 1
    vector<int>::iterator it = v.begin();

    int max_val = *it;
    for (it = next(v.begin()); it!=v.end(); it++)
        if (*it > max_val)
            max_val = *it;

    cout << "max_val = "<< max_val << endl;

    // Encontrar el Maximo: Metodo 2
    it = max_element(v.begin(), v.end());
    cout << "max_val = "<< *it << endl;

    // Encontrar el Promedio: Metodo 1
    float suma = 0.;
    for (it = v.begin(); it!=v.end(); it++)
        suma += *it;
    cout << "promedio = "<< suma / v.size() << endl;

    // Encontrar el Promedio: Metodo 2
    float promedio = accumulate(v.begin(), v.end(), 0.0) / v.size();
    cout << "promedio = "<< promedio << endl;
    
    return 0;
}