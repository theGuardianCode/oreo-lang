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

    int linecount = 0;
    bool done = false;
    while (std::getline(File, text) && done == false) {
        // look ahead until it finds a space
        for (int i = 0; i < text.length(); i++) {
            tokenValue.push_back(text[i]);
            if (text[i+1] == ' ' || text[i+1] == ';') {
                currentToken = lex(tokenValue);
                std::cout << currentToken.value << ": " << currentToken.type << "\n";
                std::cout << "Break" << std::endl;
                tokenValue = "";
                // done = true;
                break;
            }
        }

        linecount++;
    }

    File.close();
    NewFile.close();

    // get token separated by space
    // std::cout << currentToken.value << ": " << currentToken.type << std::endl;
}