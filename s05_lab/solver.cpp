#include <iostream>
#include <sstream> //stringstream
#include <vector>
#include <algorithm>

using matrix = std::vector<std::string>;

struct Pos {
    int l, c;
    Pos(int l, int c): l(l), c(c){}
};

std::vector<Pos> get_neib(Pos p) {
    auto [l, c] = p;
    return {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

std::vector<Pos> shuffle(std::vector<Pos> vet) {
    std::random_shuffle(begin(vet), end(vet));
    return vet;
}

bool pode_furar(matrix& mat, Pos p) {
    int nl = mat.size();
    int nc = mat[0].size();
    {
        auto [l, c] = p;
        if (l < 0 || l >= nl || c < 0 || c >= nc)
            return false;
        if (mat[l][c] != '#')
            return false;    
    }
    int cont { 0 };
    for (auto viz : get_neib(p)) {
        auto [l, c] = viz;
        if (l < 0 || l >= nl || c < 0 || c >= nc)
            continue;
        if(mat[viz.l][viz.c] == '#')
            cont += 1;
    }
    return (cont >= 3);
}

void show(matrix& mat) {
    for (auto line : mat)
        std::cout << line << '\n';
    getchar();
}

std::vector<Pos> get_neib_furaveis(matrix& mat, Pos p) {
    std::vector<Pos> furaveis;
    for(auto viz : get_neib(p))
        if (pode_furar(mat, viz))
            furaveis.push_back(viz);
    return furaveis;
}

void furar(matrix& mat, Pos p) {
    std::vector<Pos> pilha;
    mat[p.l][p.c] = '.';
    pilha.push_back(p);
    while (!pilha.empty()) {
        auto topo = pilha.back();
        auto furaveis = shuffle(get_neib_furaveis(mat, topo));
        if (furaveis.size() != 0) {
            auto escolhido = furaveis[0];
            mat[escolhido.l][escolhido.c] = '.';
            show(mat);
            pilha.push_back(escolhido);
        } else {
            pilha.pop_back();
        }
    }
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        std::cout << "Numero de argumentos invalidos\n";
        std::cout << "./executavel nl nc\n";
        exit(1);
    }
    int nl { 0 }, nc { 0 };
    std::stringstream(argv[1]) >> nl;
    std::stringstream(argv[2]) >> nc;
    std::vector<std::string> mat(nl, std::string(nc, '#'));

    furar(mat, Pos(1, 1));
}