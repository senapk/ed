#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> inverter_com_copia(const vector<int>& v){
    int cont { 0 };
    
    int x { 6.7 };

    unsigned int i = -7;
}


void print(auto &ss, auto& vet, int i) {
    if (i == (int) vet.size())
        return;
    ss << vet[i] << " ";
    print(ss, vet, i + 1);
};

std::string to_string(vector<int> vet) {
    stringstream ss;
    ss << "[ ";
    print(ss, vet, 0);
    ss << "]";
    return ss.str();
}

// vector<vector<int>> fazer_triangulo(std::vector<int> vet) {
//     vector<vector<int>> resp;
//     resp.push_back(vet);
//     while (vet.size() > 1) {
//         auto copia = vet;
//         vet.clear();
//         for (int i = 0; i < (int) copia.size() - 1; i++)
//             vet.push_back(copia[i] + copia[i + 1]);
//         resp.push_back(vet);
//     }
//     return resp;
// }

vector<vector<int>> fazer_linha(vector<int> vet) {
    if (vet.size() <= 1) {
        return {vet};
    }
    
    vector<int> filho;
    for (int i = 0; i < (int) vet.size() - 1; i++)
        filho.push_back(vet[i] + vet[i + 1]);
    auto resp = fazer_linha(filho);
    resp.push_back(vet);

}

int main() {
    fazer_linha({1, 2, 3, 4, 5, 7});
}

// {[113]}
// {[113], [48 65]}
// {[113], [48 65], [20 28 37]}
// {[113], [48 65], [20 28 37], [8 12 16 19]}
// {[113], [48 65], [20 28 37], [8 12 16 19], [3 5 7 9 12]}
// {[113], [48 65], [20 28 37], [8 12 16 19], [3 5 7 9 12]}, 