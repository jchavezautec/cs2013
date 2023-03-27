#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Referencias Rvalue
    int i = 7;          // i es un Lvalue, pero 7 es un Rvalue
    int k = i+3;        // (i+3) es un Lvalue
    //int *pi = &(i + 3); 

    int &b1 = i; // OK
    //int &&c1 = a; // ERROR
    //int &b2 = a * 42; // ERROR

    int &&c2 = i * 42;
    int &&c3 = 9;
    const int &d2 = i * 42; // OK

    int &&rr2 = move(c3);
}