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
    // Node node = {tokenVec[1].value, new Node({tokenVec[0].value, NULL, NULL}), new Node({tokenVec[2].value, NULL, NULL})};
    // syntaxTree.push_back(node);
    for (int i = 0; i < length; i++) {
        if (is_operator(tokenVec[i].value) != "") {
            Node node = {tokenVec[i].value, new Node({tokenVec[i-1].value, NULL, NULL}), new Node({tokenVec[i+1].value, NULL, NULL})};
            syntaxTree.push_back(node);
        }
    }

    for (int i = 0; i < syntaxTree.size(); i++) {
        std::cout << syntaxTree[i].left->data << " -> " << syntaxTree[i].data << " <- " << syntaxTree[i].right->data << "\n";
    }
}