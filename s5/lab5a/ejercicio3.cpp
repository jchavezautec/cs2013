#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class powerInt{
private:
    int _exp;
public:
    powerInt(int exp): _exp(exp){}

    int operator() (int num) {
        return pow(num, _exp);
    }
};

template<class T>
class printArray{
private:
    char _end;
public:
    printArray(char c = ' '): _end(c) {}
    void operator() (T x){
        cout << x << _end;
    }
};

int main(){
    int A[] = {1,2,3,4,5};
    for_each(A, A + 5, printArray<int>(' '));
    
    cout << endl;
    transform(A, A + 5, A, powerInt(3));
    for_each(A, A + 5, printArray<int>(' '));
    cout << endl;
    
    return 0;
}