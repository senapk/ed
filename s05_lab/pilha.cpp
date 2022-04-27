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

void furar(matrix& mat, Pos p) {
    int nl = mat.size();
    int nc = mat[0].size();
    auto [l, c] = p;
    if (l < 0 || l >= nl || c < 0 || c >= nc)
        return;
    if (mat[l][c] != '#')
        return;
    if (!pode_furar(mat, p))
        return;
    mat[l][c] = '.';
    show(mat);
    for(auto viz : shuffle(get_neib(p)))
        furar(mat, viz);
    mat[l][c] = ' ';
    show(mat);
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