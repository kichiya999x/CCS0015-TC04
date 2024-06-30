#include<iostream>
using namespace std;

class Tree{
    private:
        struct TreeNode{
            int value;
            TreeNode *left;
            TreeNode *right;
        };

    public:
        TreeNode *root;
        Tree();
        void insertNode(int);
        void inOrderTraversal(TreeNode *);
        void preOrderTraversal(TreeNode *);
        void postOrderTraversal(TreeNode *);
};

Tree::Tree(){
    root = NULL;
}

void Tree::insertNode(int val){
    TreeNode *current, *node;

    // Create a new node, set the data values and the pointers
    node = new TreeNode;
    node->value = val;
    node->left = NULL;
    node->right = NULL;

    if(root == NULL){
        // Make the new node as the root
        root = node;
        cout << "Value is inserted, node is now the root...\n";
    }else{
        // The loop will look for the correct branch where the new
        //   node will be inserted
        current = root;
        while(current != NULL){
            // Node is inserted to the left
            if(val < current->value){
                if(current->left == NULL){
                    // If left pointer of the current node is empty
                    current->left = node;
                    cout << "Value is inserted as left child...\n";
                    break;
                }else{
                    // If left pointer of the current hase value
                    // Go to the next node
                    current = current->left;
                }
            }else if(val > current->value){ // Node is inserted to the right
                if(current->right == NULL) {
                    current->right = node;
                    cout << "Value is inserted as right child...\n";
                    break;
                }else{
                    current = current->right;
                }
            }else{
                cout << "Value already exists...\n";
                break;
            }
        }
    }
}

void Tree::inOrderTraversal(TreeNode *current){
    // Left -> root -> right
    if(current != NULL){
        inOrderTraversal(current->left);
        cout << current->value << endl;
        inOrderTraversal(current->right);
    }
}

void Tree::preOrderTraversal(TreeNode *current){
    // root -> left -> right
    if(current != NULL){
        cout << current->value << endl;
        inOrderTraversal(current->left);
        inOrderTraversal(current->right);
    }
}

void Tree::postOrderTraversal(TreeNode *current){
    //  Left -> right -> root
    if(current != NULL){
        inOrderTraversal(current->left);
        inOrderTraversal(current->right);
        cout << current->value << endl;
    }
}