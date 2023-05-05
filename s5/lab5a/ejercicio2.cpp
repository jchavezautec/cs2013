#include <iostream>
#include <cmath>
#include <algorithm>
#include <time.h>

using namespace std;

struct Cifrado{
    int _a, _b;
    Cifrado(int a, int b): _a(a), _b(b){}
    char operator()(char input){ 
        return ((input - 'A')*_b + _a) % 26 + 'A';
    }
};

int main(){
    Cifrado c(3,7);
    string s = "HOLA";

    cout << "Original: " << s << endl;
    transform(s.begin(), s.end(), s.begin(), c);
    cout << "Cifrado : " << s << endl;

    return 0;
}