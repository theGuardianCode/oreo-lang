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
    Node node = {tokenVec[1].value, new Node({tokenVec[0].value, NULL, NULL}), new Node({tokenVec[2].value, NULL, NULL})};
    syntaxTree.push_back(node);
    std::cout << syntaxTree[0].left->data << " -> " << syntaxTree[0].data << " <- " << syntaxTree[0].right->data << "\n";
}