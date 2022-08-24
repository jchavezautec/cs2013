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

    cout << "Ingresar un numero de 16 digitos: ";
    
    for (int pos=1; pos <= 16; pos++){
        cin >> digito;

        if (pos % 2 == 0)
            checksum += digito - '0';
        else
            checksum += duplicarDigito(digito - '0');
    }

    cout << "El checksum es: " << checksum << ".\n";

    if (checksum % 10 == 0)
        cout << "El checksum es divisible entre 10. Es valido.\n";
    else
        cout << "El checksum no es divisible entre 10. No es valido\n";

    return 0;
}