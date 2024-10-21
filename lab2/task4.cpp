#include <iostream>
#include <stack>
#include <string>

// Function to check if a character is an opening parenthesis
bool isOpening(char c) {
    return c == '(' || c == '{' || c == '[';
}

// Function to check if two characters are matching parentheses
bool isMatching(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check for balanced parentheses in an expression
bool areParenthesesBalanced(const std::string& expression) {
    std::stack<char> s;

    // Traverse the expression character by character
    for (char c : expression) {
        if (isOpening(c)) {
            s.push(c);  // Push opening parentheses onto the stack
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty() || !isMatching(s.top(), c)) {
                return false;  // Unmatched closing parenthesis
            }
            s.pop();  // Pop the matching opening parenthesis
        }
    }

    return s.empty();  // Stack should be empty if all parentheses are balanced
}

int main() {
    std::string expression;

    // Input a mathematical expression
    std::cout << "Enter a mathematical expression: ";
    std::getline(std::cin, expression);

    // Check if the expression has balanced parentheses
    if (areParenthesesBalanced(expression)) {
        std::cout << "The parentheses are balanced.\n";
    } else {
        std::cout << "The parentheses are not balanced.\n";
    }

    return 0;
}
