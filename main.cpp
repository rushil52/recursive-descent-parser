#include <iostream>
#include <string>

using namespace std;

string input;
int pos = 0;

// Function to check and match a character
bool match(char expected) {
    if (pos < input.length() && input[pos] == expected) {
        pos++;
        return true;
    }
    return false;
}

// Forward declarations
bool E();
bool T();
bool F();

// Grammar:
// E -> T { + T }
// T -> F { * F }
// F -> (E) | i

// Parse Expression
bool E() {
    if (!T())
        return false;

    while (match('+')) {
        if (!T())
            return false;
    }

    return true;
}

// Parse Term
bool T() {
    if (!F())
        return false;

    while (match('*')) {
        if (!F())
            return false;
    }

    return true;
}

// Parse Factor
bool F() {
    // If input is an identifier
    if (match('i'))
        return true;

    // If expression is inside brackets
    if (match('(')) {
        if (!E())
            return false;

        if (!match(')'))
            return false;

        return true;
    }

    return false;
}

int main() {
    cout << "Recursive Descent Parser\n";
    cout << "Grammar: E -> T {+T}, T -> F {*F}, F -> (E) | i\n";

    cout << "Enter input string: ";
    cin >> input;

    pos = 0;

    // Check if the complete input follows the grammar
    if (E() && pos == input.length()) {
        cout << "Input string is ACCEPTED.\n";
    } else {
        cout << "Input string is REJECTED.\n";
    }

    return 0;
}