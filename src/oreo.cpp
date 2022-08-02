#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "lexer.hpp"

using std::string;

// Function declarations

int main() {
    string text;
    string tokenValue = "";
    std::ifstream File("src/Code.oreo");
    std::ofstream NewFile("out/Scribe.txt");

    std::vector<Token> tokens;

    while (!File.eof()) {
        // look ahead until it finds a break character
        text = File.get();

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ' || File.eof()) {
                tokens.push_back(lex(tokenValue));
                tokenValue = "";
                break;
            } else {
                tokenValue.push_back(text[i]);
            }
        }
    }

    // parse happens here

    File.close();
    NewFile.close();
}