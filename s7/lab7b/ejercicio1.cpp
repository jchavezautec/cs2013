#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <assert.h>

using namespace std;

template<class It>
void print_container(It begin, It end){
    for (auto it=begin; it!=end; it++)
        cout << *it << " ";
    cout << endl;
}
template<class T>
void bubble_sort(vector<T>& A){
    for (int i = 0; i < A.size()-1; i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j],A[j+1]);
}

template<class T>
void insertion_sort(vector<T>& A){
    for(std::size_t j = 1; j < A.size(); j++){
        T key = A[j];
        int i = j-1;

        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

template<class T>
void is_sorted(vector<T> A){
    for(std::size_t j = 1; j < A.size(); j++){
        assert(A[j-1] <= A[j]);
    }
}
int main(){
    srand((unsigned)time( NULL ) );
    chrono::time_point<std::chrono::system_clock> inicio, fin;
    vector<double> A(200000);
    vector<double> B(200000);
    generate(A.begin(), A.end(), [](){return (double)rand()/RAND_MAX;});
    B = A;

    inicio = chrono::high_resolution_clock::now(); // Temporizador: Inicio
    bubble_sort(A);
    fin    = chrono::high_resolution_clock::now(); // Temporizador: Fin
    is_sorted(A);
    std::chrono::duration<double, std::milli> t1 = fin - inicio;
    cout << "bubble_sort(time) = " << t1.count() << "ms" << endl;

    //is_sorted(B);
    inicio = chrono::high_resolution_clock::now(); // Temporizador: Inicio
    insertion_sort(B);
    fin    = chrono::high_resolution_clock::now(); // Temporizador: Fin
    is_sorted(B);

    std::chrono::duration<double, std::milli> t2 = fin - inicio;
    cout << "insertion_sort (time) = " << t2.count() << "ms" << endl;
    return 0;
}

//print_container(A.begin(), A.end());
//auto t = chrono::duration_cast<chrono::millioseconds>(fin - inicio).count();
//cout << t << "ms" << endl;
