#include <iostream>
#include <stack>
using namespace std;

int countMinReplacements(string str)
{
    stack<char> st;
    int replacements = 0;

     for (int i = 0; i < str.size(); i++) 
     {

        if (str[i] == '{')
        {
            st.push(str[i]);
        }
        else 
        {
            if (str[i] == '}' && !st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else 
            {
                replacements++;
            }
        }
     }
    replacements += st.size();
    return replacements;
}

int main()
{
    string braces;
    char choice;

    do {
        cout << "Enter a string of braces: ";
        cin >> braces;

        int replacements = countMinReplacements(braces);
        cout << "Minimum number of replacements required: " << replacements << endl;

        cout << "Do you want to enter another string? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}