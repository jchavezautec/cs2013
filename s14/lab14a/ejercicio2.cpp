#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<char>>& islas, int i, int j){
    // Si se sale de los limites
    if (i < 0 || i >= islas.size() || j < 0 || j >= islas[0].size())
        return;
    if (islas[i][j] == '0') // Si es agua o ya fue visitado
        return;
    islas[i][j] = '0'; // Marcando como visitado

    // Explorando las 4 direcciones
    DFS(islas,i+1,j);
    DFS(islas,i-1,j);
    DFS(islas,i,j+1);
    DFS(islas,i,j-1);
}

int contar_islas(vector<vector<char>> islas){
    int cont = 0;

    // Para cada celda en el mapa
    for(int i = 0; i < islas.size(); i++){
        for(int j = 0; j < islas[0].size(); j++){
            // Si estamos dentro de una isla
            if (islas[i][j] == '1'){
                cont++;
                // Exploramos la isla y marcamos 
                // todas las celdas como visitadas
                DFS(islas,i,j);
            }
        }
    }
    return cont;
}

int main(){
    vector<vector<char>> islas = 
        {{'1','1','0','1','1'},
         {'1','1','0','1','1'},
         {'0','0','1','0','0'},
         {'0','0','0','1','1'}};
    
    cout << contar_islas(islas) << endl; // Salida: 4
}