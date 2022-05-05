#include <iostream>
#include <sstream>

struct Node {
    int value;
    Node * next;
    Node * prev;
    Node(int value = 0, Node * next = nullptr, Node * prev = nullptr):
        value(value), next(next), prev(prev){}
};

struct DList {
    Node * head;
    Node * tail;

    DList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    ~DList() {
        auto node = head;
        while (node != nullptr) {
            auto next = node->next;
            delete node;
            node = next;
        }
    }

    bool empty() {
        return head->next == tail;
    }

    void push_front(int value) {
        insert_after(head, value);
        // Node * node = new Node(value);
        // node->next = head->next;
        // node->next->prev = node;
        // head->next = node;
        // node->prev = head;
    }

    void push_back(int value) {
        insert_after(tail->prev, value);
        // Node * node = new Node(value, tail, tail->prev);
        // tail->prev->next = node;
        // tail->prev = node;
    }

    void insert_after(Node * node, int value) {
        Node * novo = new Node(value, node->next, node);
        node->next->prev = novo;
        node->next = novo;
    }

    void erase(Node * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void pop_back() {
        if (!this->empty())
            this->erase(tail->prev);
    }
    void pop_front() {
        if (!this->empty())
            this->erase(head->next);
    }

    std::string str() {
        std::stringstream ss;
        ss << "[ ";
        for (auto node = head->next; node != tail; node = node->next)
            ss << node->value << " ";
        ss << "]\n";
        return ss.str();
    }

};

int main() {
    DList l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);

    std::cout << l.str() << '\n';

    l.pop_front();
    std::cout << l.str() << '\n';

    l.pop_back();
    std::cout << l.str() << '\n';
}