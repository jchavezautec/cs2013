#include <iostream>

using namespace std;
struct Nodo{
    int key;
    Nodo* left;
    Nodo* right;
};

class BST{
    private:
        Nodo* root;
    public:
        BST(){
            root=NULL;
        }
        void insert(int x, Nodo* leaf){
            if (x < leaf->key){
                if (leaf->left==NULL){
                    leaf->left=new Nodo;
                    leaf->left->key=x;
                    leaf->left->left=NULL;
                    leaf->left->right=NULL;
                }
                else{
                    insert(x, leaf->left);
                }
            }
            else{
                if (leaf->right==NULL){
                    leaf->right=new Nodo;
                    leaf->right->key=x;
                    leaf->right->left=NULL;
                    leaf->right->right=NULL;
                }
                else{
                    insert(x, leaf->right);
                }
            }
        }
        void insert(int x){
            if (root==NULL){
                root = new Nodo;
                root->key=x;
                root->left=NULL;
                root->right=NULL;
            }  
            else{
                insert(x, root);
            }
        }
        void in_order_tree_walk(Nodo* nodo){
            if (nodo != NULL){
                in_order_tree_walk(nodo->left);
                cout << nodo->key << " ";
                in_order_tree_walk(nodo->right);
            }
        }
        void print_tree(){
            in_order_tree_walk(root);
            cout << endl;
        }
};
int main() {
  BST bst;
  bst.insert(5);
  bst.insert(4);
  bst.insert(6);
  bst.insert(2);
  bst.insert(3);
  bst.insert(1);
  bst.print_tree();
}