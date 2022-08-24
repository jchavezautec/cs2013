#include <iostream>

using namespace std;

void insertionSort(int arr[], int arr_size){
    int i, key;

    for (int j = 1; j < arr_size; j++){
        key = arr[j];
        i = j - 1;
        
        while (arr[i] > key && i >= 0){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;
    }
}

void printArray(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++)
        cout << i << ": "<< arr[i] << ", ";
    cout << endl;
}

int main(){
    int arr[] = {0,3,6,7,1,2,3,4,3,6};
    int arr_size = sizeof(arr) / sizeof(int);

    insertionSort(arr, arr_size);
    
    int moda = arr[0];
    int maxRepeticiones = 0;
    int repeticiones = 0;

    for (int i = 0; i < arr_size; i++){
        repeticiones++;
        if (arr[i] != arr[i+1] || i == arr_size - 1){
            if (repeticiones > maxRepeticiones){
                maxRepeticiones = repeticiones;
                moda = arr[i];
            }
            repeticiones = 0;
        }
    }

    cout << "El numero mas repetido es: " << moda << endl;

    return 0;
}