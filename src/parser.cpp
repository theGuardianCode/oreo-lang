#include "lexer.hpp"
#include "parser.hpp"
#include <string>
#include <iostream>
#include <vector>

using std::string;

Parser::Parser(std::vector<Token> _tokens) {
    tokens = _tokens;
}

Token Parser::advance() {
    TokenIndex += 1;
    if (TokenIndex < tokens.size()) {
        CurrentTok = tokens[TokenIndex];
    }
    return CurrentTok;
}

Node Parser::factor() {
    Token token = CurrentTok;

    if (token.type == "integer" || token.type == "float") {
        std::cout << "Test\n";
        advance();
        return Node(token);
    }
}

Node Parser::term() {
    Node left = factor();

    while (is_operator(CurrentTok.value) == "multiply" || is_operator(CurrentTok.value) == "divide") {
        Token OperatorToken = CurrentTok;
        advance();
        Node right = factor();
        left = Node(OperatorToken, &left, &right);
    }

    return left;
}

Node Parser::expression() {
    Node left = term();

    while (is_operator(CurrentTok.value) == "add" || is_operator(CurrentTok.value) == "subtract") {
        Token OperatorToken = CurrentTok;
        advance();
        Node right = term();
        left = Node(OperatorToken, &left, &right);
    }

    return left;
}

Node Parser::Parse() {
    Node result = expression();
    return result;
}

/*
void parse(std::vector<Token> tokenVec, int length) {
    std::vector<Node> syntaxTree;
    for (int i = 0; i < length; i++) {
        if (is_operator(tokenVec[i].value) != "") {
            Node node = {tokenVec[i].value, tokenVec[i].type, new Node({tokenVec[i-1].value, tokenVec[i-1].type, NULL, NULL}), new Node({tokenVec[i+1].value, tokenVec[i+1].type, NULL, NULL})};
            for (int j = 0; j < length; j++) {
                std::cout << node.right->data << "\n";
                if (is_operator(tokenVec[j].value) != "") {
                    node.right = new Node({tokenVec[j].value, tokenVec[j].type, new Node({tokenVec[j-1].value, tokenVec[j-1].type, NULL, NULL}), new Node({tokenVec[j+1].value, tokenVec[j+1].type, NULL, NULL})});
                }
            }
            syntaxTree.push_back(node);
        }
    }

    for (int i = 0; i < syntaxTree.size(); i++) {
        std::cout << syntaxTree[i].left->data << " -> " << syntaxTree[i].data << " <- " << syntaxTree[i].right->data << "\n";
    }
}
*/