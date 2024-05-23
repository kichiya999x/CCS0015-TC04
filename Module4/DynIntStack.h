#include <iostream>
using namespace std;

class DynIntStack
{
private:
    struct StackNode
    {
        int value;
        StackNode *next;
    };
    StackNode *top;

public:
    DynIntStack();
    void push(int num);
    int pop();
    bool isEmpty();
};

//************************************************
// Constructor definition
//************************************************
DynIntStack::DynIntStack()
{
    top = NULL;
}

//************************************************
// Member function push pushes the argument onto *
// the stack. *
//************************************************
void DynIntStack::push(int num)
{
    StackNode *newNode;
    // Allocate a new node & store Num
    newNode = new StackNode;
    newNode->value = num;
    // If there are no nodes in the list
    // make newNode the first node
    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else // Otherwise, insert NewNode before top
    {
        newNode->next = top; // Connect the newly created node to the current topmost node
        top = newNode; // Set the newly created node as the new top node
    }
}
//****************************************************
// Member function pop pops the value at the top *
// of the stack off, and copies it into the variable *
// passed as an argument. *
//****************************************************
int DynIntStack::pop()
{
    StackNode *temp;
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else // pop value off top of stack
    {
        int num;
        num = top->value; // Retrieve the value of the top node
        temp = top->next; // Temporarily store the address of the second node
        delete top; // Delete the top node
        top = temp; // Set the second as the new top node
        return num; // return the value
    }
}
//****************************************************
// Member function isEmpty returns true if the stack *
// is empty, or false otherwise. *
//****************************************************
bool DynIntStack::isEmpty()
{
    // return (top == NULL)? true:false;
    if (!top) // if (top == NULL)
        return true;
    else
        return false;
}
