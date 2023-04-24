#include <iostream>

using namespace std;

void printArray(int A[], int n){
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

void bubbleSort(int A[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j],A[j+1]);
}

void bubbleSortMod(int A[], int n, bool(*comp)(int, int)){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (comp(A[j], A[j + 1]))
                swap(A[j],A[j+1]);
}

bool compasc(int a, int b){ return a > b;}
bool compdes(int a, int b){ return a < b;}

int main(){
    int A[] = {4,2,1,7,-1,5,0};
    int szA = sizeof(A)/sizeof(A[0]);
    printArray(A, szA);

    bubbleSortMod(A, szA, &compasc);
    printArray(A, szA);

    bubbleSortMod(A, szA, &compdes);
    printArray(A, szA);

    return 0;
}

