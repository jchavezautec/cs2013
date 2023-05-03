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

void bubbleSortMod(vector<int> &A, bool (*comp)(int, int)){
    for (int i = 0; i < A.size() - 1; i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (comp(A[j], A[j + 1]))
                swap(A[j],A[j+1]);
}

bool compasc(int a, int b){ return a > b;}
bool compdes(int a, int b){ return a < b;}
bool compabs(int a, int b){ return abs(a) > abs(b);}

int main(){
    vector<int> A = {5, 2, -4, 6, 1, -3};
    bubbleSort(A);
    for_each(A.begin(), A.end(), [](int x){cout << x << " ";}); cout << endl;

    vector<int> B = {5, 2, 4, 6, 1, -3};
    bubbleSortMod(B, compasc);
    for_each(B.begin(), B.end(), [](int x){cout << x << " ";}); cout << endl;

    bubbleSortMod(B, compdes);
    for_each(B.begin(), B.end(), [](int x){cout << x << " ";}); cout << endl;

    bubbleSortMod(B, compabs);
    for_each(B.begin(), B.end(), [](int x){cout << x << " ";}); cout << endl;

    return 0;
}
