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

    cout <<"\nEnter a value to search: ";
    cin >> val;
    if(tree.search(val)){
        cout << "The value " << val << " is found!";
    }else{
        cout << "The value " << val << " is not found!";
    }
    
    cout <<"\nEnter a value to delete: ";
    cin >> val;
    if(tree.deleteNote(val)){
        cout << "The value " << val << " has been deleted!";
    }else{
        cout << "No deletions were made, either the tree is empty or the value is not found.";
    }

    cout << endl << "Displaying the Binary Tree after deletion:\n";
    tree.inOrderTraversal(tree.root);
}