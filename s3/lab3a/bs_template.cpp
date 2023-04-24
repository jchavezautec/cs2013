#include <iostream>

using namespace std;

void BubbleSort(int a[], int n){
    int right = n-1;
    int temp  = 0;
    int k;
    while(right > 0){
        k = 0;
        for(int i=0; i<right; i++){
            if(a[i+1] < a[i]){
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                k = i;
            }
        }
        right = k;
    }
}

template <class T>
void BubbleSort(T a[], int n){
    int right = n-1;
    T temp  = 0;
    int k;
    while(right > 0){
        k = 0;
        for(int i=0; i<right; i++){
            if(a[i+1] < a[i]){
                temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
                k = i;
            }
        }
        right = k;
    }
}

int main(){
    int a[] = {3, 7, 1, 9, 5, 6, 2, 8, 4};
    int n = sizeof(a) / sizeof(a[0]);

    BubbleSort(a, n);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;

    
    double b[] = {3.1, 7.2, 1.3, 9.4, 5.5, 6.6, 2.7, 8.8, 4.9};
    n = sizeof(b) / sizeof(b[0]);

    BubbleSort(b, n);

    for(int i=0; i<n; i++)
        cout << b[i] << " ";
    cout << endl;
    
    return 0;
}