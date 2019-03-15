#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

struct Token {
    char token;
    char bracketType;
    bool opening;
    bool isBracket;

    Token(char token): token(token) {
        if (token == '{' || token == '(' || token == '[') {
            opening = true;
            isBracket = true;
        } else if (token == '}' || token == ')' || token == ']') {
            opening = false;
            isBracket = true;
        } else {
            opening = false;
            isBracket = false;
        }

        if (token == '{' || token == '}') {
            bracketType = 'C';
        } else if (token == '(' || token == ')') {
            bracketType = 'P';
        } else if (token == '[' || token == ']') {
            bracketType = 'S';
        } else {
            bracketType = '0';
        }
    }
};

int main() {
    string s = "{for(int i = 0; i < values]; i++)\n((()))2";
    // vector<Token> tokens;
    stack<Token> stack;
    for (auto i = s.begin(); i != s.end(); i++) {
        Token t = Token(*i);
        // tokens.push_back(t);
        if (t.isBracket && t.opening) {
            stack.push(t);
        } else if (t.isBracket && !t.opening && stack.top().bracketType == t.bracketType) {
            stack.pop();
        }
    }

    if (stack.size() != 0) {
        cout << "Error: No matching bracket found for " << stack.top().token << endl;
        cout << stack.size() << endl;
        // cout << stack << endl;
    }
    

    return 0;
}