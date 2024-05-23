#include <iostream>
using namespace std;

class DynCharStack {
private:
    struct StackNode {
        char value;
        StackNode *next;
    };
    StackNode *top;

public:
    DynCharStack();
    void push(char brace);
    char pop();
    bool isEmpty();
};

DynCharStack::DynCharStack() {
    top = NULL;
}

void DynCharStack::push(char brace) {
    StackNode *newNode = new StackNode;
    newNode->value = brace;
    newNode->next = top;
    top = newNode;
}

char DynCharStack::pop() {
    if (isEmpty()) {
        cout << "The stack is empty.\n";
        return '\0'; // Return null character if stack is empty
    } else {
        StackNode *temp = top;
        char brace = top->value;
        top = top->next;
        delete temp;
        return brace;
    }
}

bool DynCharStack::isEmpty() {
    return (top == NULL);
}

int findMinimumReplacements(const string& braces) {
    DynCharStack stack;

    for (char ch : braces) {
        if (ch == '{') {
            stack.push(ch);
        } else if (ch == '}') {
            if (!stack.isEmpty() && stack.pop() == '{') {
                // Match found, pop opening brace
            } else {
                stack.push(ch); // Push closing brace if no match found
            }
        }
    }

    // To balance the string, half of the unmatched braces need to be replaced.
    return (stack.isEmpty() ? 0 : (stack.isEmpty() + 1) / 2);
}

int main() {
    while (true) {
        string braces;
        cout << "Enter a string of braces: ";
        cin >> braces;

        int replacements = findMinimumReplacements(braces);
        cout << "Minimum number of replacements required: " << replacements << endl;

        char choice;
        cout << "Do you want to enter another string? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    return 0;
}
