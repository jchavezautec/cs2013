#include <iostream>

using namespace std;

void printArray2D(int A[][2], int n){
    for (int i = 0; i < n; i++)
        cout << "("<<A[i][0] <<","<< A[i][1]<< ") ";
    cout << endl;
}

class sumComp{
private:
    char op;
public:
    sumComp(char c): op(c){}
    int operator() (int num1, int num2){
        if (op == '+') 
            return num1 + num2;
        else if (op == '*')
            return num1 * num2;
        else
            return num1;
    }
};

void bubbleSort2D(int A[][2], int n, sumComp F){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (F(A[j][0],A[j][1]) > F(A[j+1][0],A[j+1][1])){
                swap(A[j][0],A[j+1][0]);
                swap(A[j][1],A[j+1][1]);
            }
}   

int main(){
    int A[4][2] = {{7,3},{2,10},{24,-21},{1,1}};
    int szA = sizeof(A)/sizeof(A[0]);
    printArray2D(A, szA);
    
    bubbleSort2D(A, szA, sumComp('+'));
    printArray2D(A, szA);

    bubbleSort2D(A, szA, sumComp('*'));
    printArray2D(A, szA);
    
    return 0;
}