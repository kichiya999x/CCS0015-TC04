#include<iostream>
#include "BinaryTree.h"
using namespace std;

int main(){
    Tree tree;
    int val;
    while(true){
        cout << "Enter a value to insert [-1 to stop]: ";
        cin >> val;
        if(val < 0) break;

        tree.insertNode(val);
    }
    
    cout << endl << "Displaying all Binary Tree data using inorder traverse:\n";
    tree.inOrderTraversal(tree.root);
    cout << endl << "Displaying all Binary Tree data using in preorder traverse:\n";
    tree.preOrderTraversal(tree.root);
    cout << endl << "Displaying all Binary Tree data using postorder traverse:\n";
    tree.postOrderTraversal(tree.root);
    
}