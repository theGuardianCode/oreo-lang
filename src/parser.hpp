#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "lexer.hpp"

struct Node {std::string data; Node* left; Node* right;};
void parse(std::vector<Token> tokenVec, int length);

#endif