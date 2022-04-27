#include <iostream>
#include <algorithm>

#include <vector>

#include <set> //TreeSet
#include <map> //TreeMap

#include <unordered_set> //HashSet
#include <unordered_map> //HashMap

std::vector<int> get_unicos(std::vector<int> vet) {
    std::unordered_set<int> unicos;
    std::vector<int> ordenados;
    for (auto elem : vet) { //O(N)
        auto [it, conseguiu] = unicos.insert(elem); //O(1)
        if (conseguiu)
            ordenados.push_back(elem); //O(1)
    }
    return ordenados;
}


std::vector<int> quem_sobrou_pessimo(std::vector<int> inicial, std::vector<int> sairam) {
    for (auto elem : sairam) { // O(N)
        auto it = std::find(begin(inicial), end(inicial), elem); // O(N)
        if (it != end(inicial))
            inicial.erase(it); // O(N)
    }
    return inicial;
}

std::vector<int> quem_sobrou_sucesso(std::vector<int> inicial, std::vector<int> sairam) {
    std::vector<int> sobraram;
    std::unordered_set<int> sairam_set(begin(sairam), end(sairam)); // O(N)

    for (auto elem : inicial) { // O(N)
        if (sairam_set.find(elem) == sairam_set.end()) //0(1)
            sobraram.push_back(elem);
    }
    return inicial;
}

std::vector<int> onde_estao_ruim(std::vector<int> inicial, std::vector<int> consultas) {
    std::vector<int> posicoes;

    auto index_of = [](auto vet, auto elem) {
        for (int i = 0; i < (int) vet.size(); i++)
            if (vet[i] == elem)
                return i;
        return -1;
    };

    for (auto elem : consultas) { // O(N)
        posicoes.push_back(index_of(inicial, elem)); //O(N)
    }
}

std::vector<int> onde_estao_bom(std::vector<int> inicial, std::vector<int> consultas) {
    
    std::unordered_map<int, int> mapa;
    for (size_t i = 0; i < inicial.size(); i++) //O(N)
        mapa[inicial[i]] = i;

    std::vector<int> posicoes;
    for (auto elem : consultas) { //O(N)
        auto it = mapa.find(elem); // 0(1)
        if (it == end(mapa))
            posicoes.push_back(-1); // O(1)
        else
            posicoes.push_back(mapa[elem]); // O(1)
    }
}

int main() {
    auto unicos = get_unicos({1,2,1,1,3,4,5,7,3,8});
    for (auto elem : unicos)
        std::cout << elem << " ";
    std::cout << '\n';

    std::map<int, std::string> nomes;
    nomes[1] = "um";
    nomes[2] = "dois";

    std::map<std::string, int> idades;
    idades["jose"] = 15; //insercao destrutiva
    
    idades.insert({"jose", 40}); //insercao nao destrutiva
    idades.insert(std::make_pair("jose", 70));
    idades.insert(std::pair<std::string, int>("jose", 70));

    idades["maria"] = 20;
    idades["bonifacio"] = 50;

    if (idades.find("maria") != idades.end())
    if (idades.count("maria") != 0) //quantas vezes a chave existe

}
