#include <iostream>

void prove(int& number) {
    std::cout << number;
}

int main() {
    int age = 15;
    prove(age);
}