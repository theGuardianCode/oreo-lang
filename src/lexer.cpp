#include <string>
#include <iostream>
#include <vector>
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

char Operators[7] = {
    '+',
    '-',
    '/',
    '*',
    '<',
    '>',
    '=',
};

string OperatorNames[7] = {
    "add",
    "subtract",
    "divide",
    "multiply",
    "greater than",
    "less than",
    "equals"
};

bool is_keyword(string* text) {
    for (int i = 0; i < 8; i++) {
        if (*text == Keywords[i]) {
            return true;
        }
    }
    return false;
}

bool is_integer(string& text) {
    for (auto ch: text) {
        if (isdigit(ch) == 0) {
            return false;
        }
    }
    return true;
}

string is_operator(string& text) {
    string twoCharOp = "";
    if (text.length() > 1) {
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                if (text[0] == Operators[i] && text[1] == Operators[j]) {
                    twoCharOp.push_back(Operators[i]);
                    twoCharOp.push_back(Operators[j]);
                    return twoCharOp;
                }
            }
        }
    }
    for (int i = 0; i < 7; i++) {
        if (text == string(1, Operators[i])) {
            return OperatorNames[i];
        }
    }
    return "";
}

Token lex(string text) {
    Token token;
    if (is_operator(text) != "") {
        std::cout << text << ": " << is_operator(text) << std::endl;
        token.type = is_operator(text);
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

    if (is_integer(text)) {
        std::cout << text << ": integer" << std::endl;
        token.type = "integer";
        token.value = text;
        token.endPos = text.length();
        return token;
    }
    
    if (is_operator(text) == "" && !is_keyword(&text) && !is_integer(text)) {
        std::cout << text << ": identifier" << std::endl;
        token.type = "Identifier";
        token.value = text;
        token.endPos = text.length();
        return token;
    }

    return token;
}