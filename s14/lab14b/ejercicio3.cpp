#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void explorarBFS(vector<vector<char>>& laberinto, int x, int y, int fx, int fy){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while (Q.size() != 0){
        pair<int,int> v = Q.front();
        Q.pop();
        if (laberinto[v.first][v.second] != 'X' && laberinto[v.first][v.second] != 'V'){
            laberinto[v.first][v.second] = 'V';
            cout << "Explorando -> " << v.first << "," << v.second << endl;
            if (v.first == fx && v.second == fy){
                laberinto[v.first][v.second] = '@';
                cout << "Encontrado" << endl;
                return;
            }
            if (v.first > 0)
                Q.push({v.first-1,v.second});
            if (v.first < laberinto.size()-1)
                Q.push({v.first+1,v.second});
            if (v.second > 0)
                Q.push({v.first,v.second-1});
            if (v.second < laberinto[0].size()-1)
                Q.push({v.first,v.second+1});
        }
    }
}

void print(vector<vector<char>>& laberinto){
    for (int i = 0; i < laberinto.size(); ++i){
        for (int j = 0; j < laberinto[0].size(); ++j){
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<char>> laberinto = 
        {{'I','X',' ','X','X'},
         {' ',' ',' ',' ',' '},
         {'X',' ','X',' ','X'},
         {'X',' ','X','F',' '},
         {' ',' ','X',' ','X'},
         {' ',' ',' ',' ','X'}};
    
    explorarBFS(laberinto,0,0,3,3);
    print(laberinto);
}