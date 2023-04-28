#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void bubbleSort(vector<int> &A){
    for (int i = 0; i < A.size() - 1; i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (A[j] > A[j+1])
                swap(A[j],A[j+1]);
}

void bubbleSortMod(vector<int> &A, bool (*func)(int, int)){
    for (int i = 0; i < A.size() - 1; i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (func(A[j],A[j+1]))
                swap(A[j],A[j+1]);
}

bool comp1(int a, int b){
    return a > b;
}
bool comp2(int a, int b){
    return a < b;
}
bool comp3(int a, int b){
    return abs(a) > abs(b);
}

int main(){
    vector<int> A = {5, 1, -7, -4, -2, 6, 3, 8};
    bubbleSortMod(A, comp1);
    for_each(A.begin(), A.end(), [](int i){cout << i << " ";}); cout << endl;

    bubbleSortMod(A, comp2);
    for_each(A.begin(), A.end(), [](int i){cout << i << " ";}); cout << endl;

    bubbleSortMod(A, comp3);
    for_each(A.begin(), A.end(), [](int i){cout << i << " ";}); cout << endl;

    return 0;
}