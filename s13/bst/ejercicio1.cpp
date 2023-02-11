#include <iostream>

using namespace std;

struct Nodo{
  int key;
  Nodo* left;
  Nodo* right;
  Nodo (int x){key=x;}
};

int main() {
  Nodo* root = new Nodo(5);
  root->left = new Nodo(4);
  root->right = new Nodo(6);

  cout << root->left->key << endl;
  cout << root->key << endl;
  cout << root->right->key << endl;
  
}