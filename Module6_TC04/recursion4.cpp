#include <iostream>
#include <cstring>
using namespace std;

int numChars(char search, char str[], int subscript){
    if (str[subscript] == '\0')
        return 0;
    else{
        if (str[subscript] == search)
            return 1 + numChars(search, str, subscript + 1);
        else
            return numChars(search, str, subscript + 1);
    }
}

int main(){
    string str;
    char letterToCount;

    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Enter character to find: ";
    cin >> letterToCount;
    int len = str.length();
    char chars[len];
    strcpy(chars, str.c_str());

    cout << "Number of times " << letterToCount
        << " appeared in the string: " << numChars(letterToCount, chars, 0);
}