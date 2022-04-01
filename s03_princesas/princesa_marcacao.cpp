#include <iostream>
#include <vector>

void show_vet(std::vector<int> vet, int sword) {
    for (int i = 0; i < (int) vet.size(); i++)
        std::cout << i << (i == sword? "> " : "  ");
    std::cout << std::endl;
}

int achar_vivo(std::vector<int>& v, int pos) {
    do {
        pos = (pos + 1) % v.size();
    } while(v[pos] == false);
    return pos;
}

int main() {
    int size {}, sword {};
    std::cin >> size >> sword;
    std::vector<int> vet(size, true);
    sword -= 1;
    int qtd = vet.size() - 1;
    while(qtd--) {
        show_vet(vet, sword);
        sword = achar_vivo(vet, sword);
        vet[sword] = false;
        sword = achar_vivo(vet, sword);
    }
}