#include <iostream>

using namespace std;

int main(){
    char digito;
    int checksum = 0;

    cout << "Ingresar un numero de seis digitos: ";
    
    for (int i=1; i <= 6; i++){
        cin >> digito;
        checksum += digito - '0';
    }

    cout << "El checksum es: " << checksum << ".\n";

    if (checksum % 10 == 0)
        cout << "El checksum es divisible entre 10. Es valido.\n";
    else
        cout << "El checksum no es divisible entre 10. No es valido\n";

    return 0;
}