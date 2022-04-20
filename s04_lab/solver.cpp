#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void mostrar(vector<string> mapa) {
    for(auto line : mapa)
        cout << line << '\n';
    getchar();
}

struct Point {
    int l;
    int c;
    Point(int l, int c): l(l), c(c) {}
    bool operator==(Point other) {
        return l == other.l && c == other.c;
    }
};

vector<Point> get_neib(Point p) {
    auto [l, c] = p; //structured binding
    return { {l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c} };
}

bool is_path(vector<string>& mapa, Point atual, Point final) {
    auto [lpos, cpos] = atual;
    auto [lfim, cfim] = final;

    int nl = mapa.size();
    int nc = mapa[0].size();
    if (lpos < 0 || lpos >= nl || cpos < 0 || cpos >= nc)
        return false;
    if (mapa[lpos][cpos] != '#')
        return false;
    if (lpos == lfim && cpos == cfim) {
        mapa[lpos][cpos] = 'o';
        mostrar(mapa);
        return true;
    }
    mapa[lpos][cpos] = 'x';
    mostrar(mapa);

    for(auto neib : get_neib(atual)) {
        if (is_path(mapa, neib, final)) {
            mapa[lpos][cpos] = 'o';
            mostrar(mapa);
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> mapa;
    ifstream arq("input.txt");
    int nl { }, nc { }, li { }, ci { };
    arq >> nl >> nc >> li >> ci;
    for(int i = 0; i < nl; i++) {
        string line;
        arq >> line;
        mapa.push_back(line);
    }

    mostrar(mapa);
    std::cout << is_path(mapa, {li, ci}, {4, 0}) << "\n";
}