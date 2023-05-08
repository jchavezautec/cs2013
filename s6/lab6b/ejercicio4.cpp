#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

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


void bubbleSort(vector<int> A){
    for (int i = 0; i < A.size() - 1; i++)
        for (int j = 0; j < A.size() - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j],A[j+1]);
    
    cout << "Ordenado, con repeticiones:" << endl;
    for_each(A.begin(), A.end(), printContainer<int>());
    cout << endl;

    set<int> s(A.begin(), A.end());
    A.clear();
    A.assign(s.begin(), s.end());

    cout << "Ordenado, sin repeticiones:" << endl;
    for_each(A.begin(), A.end(), printContainer<int>());
    cout << endl;
}

int main(){
    vector<int> A(100);
    generate(A.begin(), A.end(), [](){return rand()%51;});
    for_each(A.begin(), A.end(), printContainer<int>());
    cout << endl;

    bubbleSort(A);

    return 0;
}

