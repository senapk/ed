#include <iostream>

int main() {
    std::cout << "Digite sua idade: ";
    int idade { };
    std::cin >> idade;
    std::cout << "Sua idade é: " << idade << '\n';
    if (idade > 150)
        std::cerr << "Idade inválida\n";
}