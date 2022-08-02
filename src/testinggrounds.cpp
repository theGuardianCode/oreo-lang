#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream File("src/Code.oreo");
    std::string value;

    std::getline(File, value);

    std::cout << value << std::endl;
}