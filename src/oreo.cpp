#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"

using std::string;

int main(int argc, char **argv) {
    string text;
    string tokenValue = "";
    std::ifstream File(argv[1]);
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
    Parser parser(tokens);
    Node ast = parser.Parse();

    std::cout << "Data: " << ast.right->data << "\n";

    File.close();
    NewFile.close();
}