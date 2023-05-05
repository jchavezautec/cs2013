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
    vector<int> v = {7,-6,5,-4,3,-2,1};

    bubbleSortMod(v, compasc);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";}); cout << endl;

    bubbleSortMod(v, compdes);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";}); cout << endl;
    
    bubbleSortMod(v, compabs);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";}); cout << endl;

    return 0;
}
