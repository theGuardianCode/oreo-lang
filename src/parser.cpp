#include "lexer.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;

struct Node {
    string data;
    Node* left;
    Node* right;
};

void parse(std::vector<Token> tokenVec, int length) {
    std::vector<Node> syntaxTree;
    syntaxTree.push_back({"+", NULL, NULL});
    std::cout << syntaxTree[0].data << "\n";
}