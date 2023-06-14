#include <iostream>
#include <stack>
#include <vector>

using namespace std;

string validar(const vector<stack<int>>& torres) {
    int discoAnterior = 0;

    for (const auto& torre : torres) {
        stack<int> torreCopia = torre;
        while (!torreCopia.empty()) {
            int disco = torreCopia.top();
            torreCopia.pop();
            if (disco <= discoAnterior) {
                return "Configuracion incorrecta!";
            }

            discoAnterior = disco;
        }
    }

    return "Configuracion correcta!";
}

int main() {
    vector<stack<int>> torres(3); // 3 torres

    // Agregar discos a las torres (configuración de ejemplo)
    torres[0].push(3);  // Torre 1: Disco con radio 3
    torres[0].push(2);
    torres[0].push(1);
    cout <<  validar(torres) << endl; // Salida: Configuracion correcta!

    torres[1].push(4);  // Torre 2: Disco con radio 4
    torres[1].push(5);
    cout <<  validar(torres) << endl; // Salida: Configuracion incorrecta!

    return 0;
}
