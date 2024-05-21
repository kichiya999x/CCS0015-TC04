#include <iostream>
using namespace std;

int findMinimumReplacements(const std::string& braces) {
    int openCount = 0, closeCount = 0;

    for (char ch : braces) {
        if (ch == '{') {
            openCount++;
        } else {
            if (openCount > 0) {
                openCount--;
            } else {
                closeCount++;
            }
        }
    }

    // The total replacements needed will be the sum of unmatched opening and closing braces.
    return (openCount + closeCount + 1) / 2;
}

int main() {
    std::string braces;
    std::cout << "Enter a string of braces: ";
    std::cin >> braces;

    int replacements = findMinimumReplacements(braces);
    std::cout << "Minimum number of replacements required: " << replacements << std::endl;

    return 0;
}
