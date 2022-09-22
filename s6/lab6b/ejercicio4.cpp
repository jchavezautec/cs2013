#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

template<class T>
class printContainer{
private:
    char _end;
public:
    printContainer(char c = ' '): _end(c) {}
    void operator() (T x){
        cout << x << _end;
    }
};


void bubbleSort(int A[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j],A[j+1]);
}

int main(){
    int A[] = {4,2,1,7,-1,5,0,2,7,6};
    int szA = sizeof(A)/sizeof(A[0]);
    
    for_each(A, A + szA, printContainer<int>());
    cout << endl;

    bubbleSort(A, szA);
    for_each(A, A + szA, printContainer<int>());
    cout << endl;

    set<int> s(A, A+szA);
    for (const int& e: A)
        s.insert(e);

    //set<int> s(A, A+szA);

    for_each(s.begin(), s.end(), printContainer<int>());
    cout << endl;

    return 0;
}

