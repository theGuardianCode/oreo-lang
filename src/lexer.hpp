#include <string>
using std::string;

struct Token {string type; string value; int endPos;};
void lex(string text);

bool is_keyword(string* text);
bool is_operator(string* text);