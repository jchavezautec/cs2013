#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

template<class C>
void print_container(C& cont){
    for (auto it=cont.begin(); it!=cont.end(); it++)
        cout << *it << " ";
    cout << endl;
}

template<class It1, class It2>
void print_container(It1 begin, It2 end){
    for (auto it=begin; it!=end; it++)
        cout << *it << " ";
    cout << endl;
}

int main(){
    chrono::time_point<std::chrono::system_clock> inicio, fin;
    vector<float> v(10);
    generate(v.begin(), v.end(), [](){return static_cast<float>(rand())/RAND_MAX;});

    inicio = chrono::high_resolution_clock::now();
    //print_container(v);
    print_container(v.begin(), v.end());

    fin    = chrono::high_resolution_clock::now();
    //auto t = chrono::duration_cast<chrono::millioseconds>(fin - inicio).count();
    //cout << t << "ms" << endl;

    std::chrono::duration<double, std::milli> t = fin - inicio;
    cout << "time = " << t.count() << "ms" << endl;

    return 0;
}