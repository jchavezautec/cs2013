#include <iostream>

using namespace std;

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << i << ": "<< arr[i] << ", ";
    cout << endl;
}

int maxElemento(int arr[], int arr_size){
    int max = arr[0];

    for (int i = 1; i < arr_size; i++){
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int main(){
    int arr[] = {0,3,6,7,1,2,3,4,3,6};
    int arr_size = sizeof(arr) / sizeof(int);
    
    int hist_size = maxElemento(arr, arr_size) + 1;
    int hist[hist_size];
    
    for (int j = 0; j < hist_size; j++)
        hist[j] = 0;

    for (int i = 0; i < arr_size; i++)
        hist[arr[i]]++;

    printArray(hist, hist_size);

    int moda = 0;
    
    for (int i = 1; i < hist_size; i++){
        if (hist[i] > hist[moda])
            moda = i;
    }

    cout << "El numero mas repetido es: " << moda << endl;

    return 0;
}