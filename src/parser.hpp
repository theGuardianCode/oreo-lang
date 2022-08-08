#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "lexer.hpp"

struct Node {
    string data;
    string type;
    Node* left;
    Node* right;

    Node(Token token, Node* _left = NULL, Node* _right = NULL) {
        data = token.value;
        type = token.type;
        if (left != NULL) {
            left = _left;
        }
        if (right != NULL) {
            right = _right;
        }
    }
};

class Parser {
    public:
        std::vector<Token> tokens;
        int TokenIndex = -1;
        Token CurrentTok;

        Parser(std::vector<Token> _tokens);
        Token advance();
        Node factor();
        Node term();
        Node expression();
        Node Parse();
};

#endif