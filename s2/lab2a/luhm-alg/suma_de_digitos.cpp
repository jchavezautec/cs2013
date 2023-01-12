#include <iostream>

using namespace std;

int duplicarDigito(int digito){
    int digitoDuplicado = digito * 2;
    int sum;

    if (digitoDuplicado >= 10)
        sum = 1 + digitoDuplicado % 10;
    else
        sum = digitoDuplicado;
    return sum;
}

int main(){
    char digito;
    int checksum = 0;

    cout << "Ingrese un numero: ";
    cin >> digito;


    cout << "¿Es la suma " << duplicarDigito(digito - '0') << " ?\n"; 
 
    return 0;
}