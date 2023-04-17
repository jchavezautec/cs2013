#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>

using namespace std;


template<template<class> class C, class T>
void print(C<T> cont){
    for(auto elemento: cont)
        cout << elemento << " ";
    cout << endl;
}

template<template<class> class C>
void print(C<int> cont){
    cout << "Para enteros:";
    for(auto elemento: cont)
        cout << elemento << " ";
    cout << endl;
}


template<typename C>
void print(C cont){
    cout << "C puede ser tambien un contenedor:";
    for(auto elemento: cont)
        cout << elemento << " ";
    cout << endl;
}

int main(){
    vector<int> v1{3,2,7};
    vector<float> v2{0.1,-3.2, 1.1};
    list<char> l1 = {'a','b','c'};
    
    //print<vector,int>(v1); // Resultado: 3 2 7
    print(v1); // Resultado: 3 2 7
    print(v2); // Resultado: 0.1 -3.2 1.1
    print(l1); // Resultado: a b c
}