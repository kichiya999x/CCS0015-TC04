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
        bool search(int key);
        bool deleteNote(int deleteKey);
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

bool Tree::search(int key){
    TreeNode *current = root;

    while(current != NULL){
        if(current->value == key){
            // If the value is found, return true
            return true;
        }else{
            if(key < current->value){
                // If the value of the search key is lesser than value of the current node,
                //   go to the left child
                current = current->left;
            }else{
                // If the value of the search key is lesser than value of the current node,
                //   go to the right child
                current = current->right;
            }
        }
    }

    // If the value is not found, return false;
    return false;
}

bool Tree::deleteNote(int deleteKey){
    TreeNode *current = root;
    TreeNode *parent = NULL;
    TreeNode *tempNode;

    // Find for the node to be deleted
    while(current != NULL && current->value != deleteKey){
        // Temporari;y store the current as the parent node
        parent = current;

        if(deleteKey < current->value){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    // If the value to be deleted is NOT found
    //     of the tree is empty
    if(current == NULL){
        return false;
    }

    if(current->left == NULL){ // **** If the node to be deleted has zero or one child
        // Deletion is in the right child
        tempNode = current->right;
        if(parent == NULL){
            // The node to be deleted is the root node
            delete tempNode;
            return true;
        }

        if(parent->left == current){
            parent->left = tempNode;
        }else{
            parent->right = tempNode;
        }
        delete current;
        return true;
    }else if(current->right == NULL){
        // Deletion is in the left child
        tempNode = current->left;
        if(parent == NULL){
            // The node to be deleted is the root node
            delete tempNode;
            return true;
        }

        if(parent->left == current){
            parent->left = tempNode;
        }else{
            parent->right = tempNode;
        }
        delete current;
        return true;
    }else{ // ****Deletion of a node with two children
        TreeNode *successor = current;
        // Detach the right subtree of the node to be deleted
        tempNode = current->right;

        // Travse the right subtree using inorder traversal
        //    until the leftmost leaf is reached
        while(tempNode->left != NULL){
            successor = tempNode;
            tempNode = tempNode->left;
        }

        // Attach the right subtree to the parent of the node to be deleted
        if(successor != current){ 
            successor->left = tempNode->right;
        }else{
            successor->right = tempNode->right;
        }

        // Copy the value in the leftmost leaf the the current parent node
        current->value = tempNode->value;
        // Delete the leftmost leaf
        delete tempNode;
        return true;
    }

    // No deletion has been made
    return false;
}