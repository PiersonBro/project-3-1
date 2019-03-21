#ifndef _TOKEN_H_
#define _TOKEN_H_
#include <string>
using namespace std;
struct Token {
    // Desc: The char of the Token
    char token;

    // Desc: Determines if the token is of a bracket
    bool isBracket;

    // Desc: The type of bracket {} [] or ()
    char bracketType;

    // Desc: Determines if it is an opening bracket { [ or (
    bool opening;

    // Desc: Constructor that takes a char input
    // Pre: char input
    // Post: Token struct that stores a char input, and has qualifiers based on the char
    Token(char token);
};

// Desc: Runs through the input and pushes brackets onto the stack
// Pre: Input to read from
// Post: Brackets on the stack
bool bracket_parser(string input);
#endif