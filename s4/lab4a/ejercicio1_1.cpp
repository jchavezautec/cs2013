#include <iostream>

using namespace std;

template<class T>
T suma(T a, T b){
    return a + b;
}

template<class T>
char suma(char a, T b){
    return a + b;
}

template<class T>
T suma(T a, char b){
    return a + b;
}

char suma(char a, char b){
    return a + b;
}

int main(){
    cout << suma(1,2) << endl;
    cout << suma(1.5,2.1) << endl;
    cout << suma('A',1) << endl;
    cout << suma(1,'A') << endl;
    cout << suma('+','-') << endl;

    return 0;
}