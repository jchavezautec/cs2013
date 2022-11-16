#include <iostream>

struct Nodo{
  int key;
  Nodo* left;
  Nodo* right;
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
          leaf->left=new Nodo;
          leaf->left->key=key;
        }
        else{
          insert(key, leaf->left);
        }
      }
      else{
        if (leaf->right==NULL){
          leaf->right=new Nodo;
          leaf->right->key=key;
        }
        else{
          insert(key, leaf->right);
        }     
      }
    }
    void insert(int key){
      if (root==NULL){
        root = new Nodo;
        root->key=key;
      }  
      else{
        insert(key, root);
      }
    }
    
};
int main() {
  BinaryTree bt;
  bt.insert(5);
  bt.insert(4);
  bt.insert(6);
}