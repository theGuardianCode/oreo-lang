#include <string>
#include <iostream>
using std::string;

struct Token {
    string type;
    string value;
    int endPos;
};


string Keywords[8] = {
    "if",
    "else",
    "elsif",
    "while",
    "for",
    "string",
    "int",
    "float"
};

string Operators[7] = {
    "+",
    "-",
    "/",
    "*",
    "<",
    ">",
    "=",
};

bool is_keyword(string* text) {
    for (int i = 0; i < 8; i++) {
        if (*text == Keywords[i]) {
            return true;
        }
    }
    return false;
}

bool is_operator(string* text) {
    for (int i = 0; i < 7; i++) {
        if (*text == Operators[i]) {
            return true;
        }
    }
    return false;
}

Token lex(string text) {
    Token token;
    if (is_operator(&text)) {
        std::cout << text << ": operator" << std::endl;
        token.type = "Operator";
        token.value = text;
        token.endPos = text.length();
        return token;
    }

    if (is_keyword(&text)) {
        std::cout << text << ": keyword" << std::endl;
        token.type = "Keyword";
        token.value = text;
        token.endPos = text.length();
        return token;
    } 
    
    if (!is_operator(&text) && !is_keyword(&text)) {
        std::cout << text << ": identifier" << std::endl;
        token.type = "Identifier";
        token.value = text;
        token.endPos = text.length();
        return token;
    }

    return token;
}