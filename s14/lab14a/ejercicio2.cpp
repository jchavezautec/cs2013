#include <iostream>

using namespace std;

struct Nodo{
  int key;
  Nodo* left;
  Nodo* right;
  Nodo(int z): key(z){};
};

class BinaryTree{
  private:
    Nodo* root;
  public:
    BinaryTree(){
      root=NULL;
    }
    void insert(int key, Nodo* leaf){
      if (key < leaf->key){
        if (leaf->left==NULL){
          leaf->left=new Nodo(key);
        }
        else{
          insert(key, leaf->left);
        }
      }
      else{
        if (leaf->right==NULL){
          leaf->right=new Nodo(key);
        }
        else{
          insert(key, leaf->right);
        }     
      }
    }
    void insert(int key){
      if (root==NULL){
        root = new Nodo(key);
      }  
      else{
        insert(key, root);
      }
    }
    void print_tree(){
      cout << root->left->key << endl;
      cout << root->key << endl;
      cout << root->right->key << endl;
    }
};
int main() {
  BinaryTree bt;
  bt.insert(5);
  bt.insert(4);
  bt.insert(6);
  bt.print_tree();
  
}