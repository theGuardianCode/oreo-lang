#ifndef LEXER_H
#define LEXER_H

#include <string>
using std::string;

struct Token {string type; string value; int endPos;};
Token lex(string text);

bool is_keyword(string* text);
bool is_integer(string& text);
string is_operator(string& text);

#endif