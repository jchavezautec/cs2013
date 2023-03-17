#include <iostream>
#include <vector>

using namespace std;

bool es_primo(int x){
  for(int i=2; i < x; i++){
    if (x % i == 0)
      return false;
  }
  return true;
}

vector<int> primos_dos_cifras(){
  vector<int> primos;
  for (int i=10; i < 100;i++){
    if (es_primo(i))
      primos.push_back(i);
  }
  return primos;
}

void print_vector(vector<int> vec){
  cout << "Los primos de dos cifras son: " << endl;
  for (auto e: vec){
    cout<< e << " ";
  }
  cout << endl;
}

void insertion_sort(int* A, int n){
  for (int j = 1; j < n; j++) {
    int key = A[j];
    int i = j - 1;
    while (A[i] > key && i >= 0) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = key;
  }
}
int main() {
  vector<int> p_2cif = primos_dos_cifras();
  print_vector(p_2cif);

  int n;
  cout << "n: ";
  cin >> n;

  int* p_rand = new int[n];
  for(int i=0; i<n; i++){
    p_rand[i] = p_2cif[rand()%p_2cif.size()];
  }

  for(int i=0; i<n; i++){
    cout << p_rand[i] << " ";
  }
  cout << endl;

  insertion_sort(p_rand, n);
  cout << "Array ordenado: " << endl;
  for(int i=0; i<n; i++){
    cout << p_rand[i] << " ";
  }
  cout << endl;
  
  delete[] p_rand;
}