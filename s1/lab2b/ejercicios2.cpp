#include <iostream>

using namespace std;

void crear_matriz(int** mat, int n, int m){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      mat[i][j] = 10 + rand() % 90;
    }
  }  
}

float promedio(int** mat, int n, int m){
  float s;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      s += mat[i][j];
    }
  }  
  return s / (n * m);
}

void print_suma(int** mat1, int** mat2, int n, int m){
  for(int i=0; i<n; i++){
    cout << "| ";
    for(int j=0; j<m; j++){
      cout.width(3);
      cout << mat1[i][j] + mat2[i][j] << " ";
    }
    cout << "|" << endl;
  }   
}
void print(int** mat, int n, int m){
  for(int i=0; i<n; i++){
    cout << "| ";
    for(int j=0; j<m; j++){
      cout << mat[i][j] << " ";
    }
    cout << "|" << endl;
  }    
}
int main() {
  int n, m;
  cout << "n: ";
  cin >> n;
  cout << "m: ";
  cin >> m;
  int** matriz = new int*[n];

  for(int i=0; i<n; i++){
    matriz[i] = new int[m];
  }

  int** matriz2 = new int*[n];

  for(int i=0; i<n; i++){
    matriz2[i] = new int[m];
  }
  crear_matriz(matriz, n, m);
  print(matriz, n, m);
  cout << "promedio = " << promedio(matriz,n,m) << endl;

  cout << endl;
  crear_matriz(matriz2, n, m);
  print(matriz2, n, m);
  cout << "promedio = " << promedio(matriz2,n,m) << endl;
  cout << "\nLa suma:" << endl;
  print_suma(matriz, matriz2, n, m);
  
  for(int i=0; i<n; i++){
    delete[] matriz[i];
  }
  delete[] matriz;

  for(int i=0; i<n; i++){
    delete[] matriz2[i];
  }
  delete[] matriz2;
}