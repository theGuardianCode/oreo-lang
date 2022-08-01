#include <string>
#include <iostream>
#include <fstream>
using std::string;

// Function declarations
bool is_keyword(string text);

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

bool is_keyword(string text) {
    for (int i = 0; i < 8; i++) {
        if (text == Keywords[i]) {
            return true;
        }
    }
    return false;
}

Token lex(string text) {
    Token token;
    if (is_keyword(text)) {
        token.type = "Keyword";
        token.value = text;
        token.endPos = text.length();
        return token;
    }
    return token;
}

int main() {
    string text;
    std::ifstream File("Code.oreo");
    std::getline(File, text);

    Token currentToken = lex(text);
    std::cout << currentToken.value << ": " << currentToken.type << std::endl;
}