#include <iostream>

using namespace std;

template<class T>
T Max(T a, T b){
    cout << "T Max(T a, T b): ";
    return a > b ? a: b;
}

int Max(char a, int b){
    cout << "T2 Max(T1 a, T2 b): ";
    return a > b ? a: b;
}

int main(){
    cout << Max(2, 1) << endl;
    cout << Max('a', 'b') << endl;
    cout << Max(0.7, 1.5) << endl;
    cout << Max('a', 1) << endl;

    return 0;
}