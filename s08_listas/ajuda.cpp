#include <iostream>
#include <vector>
#include <sstream>

struct Pacote {
    int value;
};

std::ostream& operator<<(std::ostream& os, Pacote pacote) {
    os << "Pacote: " << pacote.value;
    return os;
}

std::istream& operator>>(std::istream& is, Pacote& pacote) {
    is >> pacote.value;
    return is;
}

std::string fmt(auto data) {
    std::ostringstream ss;
    ss << "[";
    for (auto it = data.begin(); it != data.end(); ++it)
        ss << (it != data.begin() ? ", " : "") << *it;
    ss << "]";
    return ss.str();
}

int main() {
    std::string data = "4 5 6 7 8 3 2 1 1";
    std::stringstream ss(data);
    
    std::vector<int> vet;
    int token { };
    while(ss >> token)
        vet.push_back(token);

    std::cout << fmt(vet) << '\n';    


    
    // Pacote x;
    // std::cin >> x;
    // std::cout << x;


}