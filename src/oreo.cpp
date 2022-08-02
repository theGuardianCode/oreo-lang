#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "lexer.hpp"

using std::string;

// Function declarations

int main() {
    string text;
    Token currentToken;
    string tokenValue = "";
    std::ifstream File("src/Code.oreo");
    std::ofstream NewFile("out/Scribe.txt");

    while (!File.eof()) {
        // look ahead until it finds a break character
        text = File.get();

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ' || File.eof()) {
                lex(tokenValue);
                tokenValue = "";
                break;
            } else {
                tokenValue.push_back(text[i]);
            }
        }
    }

    File.close();
    NewFile.close();

    // get token separated by space
    // std::cout << currentToken.value << ": " << currentToken.type << std::endl;
}