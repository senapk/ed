#include <iostream>
#include <vector>

template <typename T>
struct vector {
    int _size;    //atributos
    int _capacity;
    T * _data;
    std::string nome;

    vector(int size = 0): _size(size), _capacity(size) {
        this->_data = new T[size];
    }

    vector(int size, T value): vector(size) {
        for (int i = 0; i < size; i++)
            _data[i] = value;
    }

    ~vector() {
        delete [] _data;
    }

    void push_back(T value) {
        if (_size == _capacity)
            this->reserve(_capacity == 0 ? 1 : 2 * _capacity);
        _data[_size] = value;
        _size += 1;
    }

    void pop_back() {
        if (_size == 0)
            return;
        _size -= 1;
    }

    T& at(int index) {
        if (index < 0 || index >= _size)
            throw std::string("indice invalido");
        return _data[index];
    }

    void reserve(int capacity) {
        T * _new_data = new T[capacity];

        int qtd = std::min(_size, capacity);
        
        for (int i = 0; i < qtd; i++)
            _new_data[i] = _data[i];
        
        _size = qtd; //pode ter diminuido
        _capacity = capacity;
        delete [] _data; //devolve o bloco antigo
        _data = _new_data; //atualiza a referencia
    }

    T& operator[](int index) {
        return _data[index];
    }

    int capacity() {
        return _capacity;
    }

    int size() {
        return _size;
    }

    T& front() {
        return _data[0];
    }

    T& back() {
        return _data[_size - 1];
    }

    T * begin() {
        return _data;
    }

    T * end() {
        return _data + _size;
    }

    void insert(T * it, T value) {
        int pos = it - _data;
        if(_size == _capacity)
            this->reserve(2 * _capacity);
        for (int i = _size; i > pos; --i)
            _data[i] = _data[i - 1];
        _size += 1;
        _data[pos] = value;
    }

    void erase(T * it) {
        int pos = it - _data;
        for (int i = pos; i < _size - 1; i++)
            _data[i] = _data[i + 1];
        _size -= 1;
    }

};

int main() {
    vector<float> vet(5, 0.1);

    std::cout << vet.size() << " " << vet.capacity() << '\n';

    vet[2] = 6;
    vet.front() = 7;
    vet.back() = 9;

    std::cout << vet[2] << ' ' << vet.front() << ' ' << vet.back() << '\n';

    auto print = [&vet] {
        std::cout << "[ ";
        for (int i = 0; i < vet.size(); i++)
            std::cout << vet[i] << ' ';
        std::cout << "] " << vet.size() << "/" << vet.capacity() << '\n';
    };

    print();
    vet.push_back(3);
    vet.push_back(4);
    print();

    vet.insert(vet.begin() + 1, 9);
    print();
    vet.erase(vet.begin() + 1);

    for (auto it = vet.begin(); it != vet.end(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';

    for (auto elem : vet)
        std::cout << elem << ' ';
    std::cout << '\n';
};