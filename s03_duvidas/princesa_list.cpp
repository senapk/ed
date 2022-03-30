#include <iostream>
#include <list>
#include <vector>
using namespace std;

void show_list(list<int>& l, list<int>::iterator& sword) {
    for (auto it = l.begin(); it != l.end(); it++)
        cout << *it << (it == sword? "> " : "  ");
    cout << endl;
}

int main() {

    int size {}, sword {};
    cin >> size >> sword;
    list<int> l;
    for (int i = 0; i < size; i++)
        l.push_back(i + 1);
    auto it_sword = next(l.begin(), sword - 1);

    auto fix_loop = [&l](auto it) {
        return it == l.end() ? l.begin() : it;
    };

    while(l.size() > 1) {
        show_list(l, it_sword);
        it_sword = fix_loop(next(it_sword, 1));
        it_sword = fix_loop(l.erase(it_sword));
    }
    show_list(l, it_sword);
}