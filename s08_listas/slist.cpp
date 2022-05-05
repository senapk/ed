#include <iostream>

struct Node {
    int value;
    Node * next;
    Node(int value = 0, Node * next = nullptr):
        value(value), next(next){
    }
};

struct List {
    Node * head {nullptr};

    List() {
    }

    bool empty() {
        return head == nullptr;
    }

    void push_front(int value) {
        auto node = new Node(value);
        node->next = head;
        head = node;
    }

    void push_back(int value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }
        auto node = head;
        while (node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    void pop_front() {
        if (head == nullptr)
            return;
        auto backup = head;
        head = head->next;
        delete backup;
    }

    // void pop_back() {
    //     if (head == nullptr)
    //         return;
    //     if (head->next = nullptr) {
    //         pop_front();
    //         return;
    //     }
    //     auto node = head;
    //     while(node->next->next != nullptr)
    //         node = node->next;
    //     delete node->next;
    //     node->next = nullptr;
    // }

    Node * __push_back(Node * node, int value) {
        if (node == nullptr)
            return new Node(value);
        node->next = __push_back(node->next, value);
        return node;
    }

    void push_back_rec(int value) {
        head = __push_back(head, value);
    }
    
    Node * __pop_back(Node * node) {
        if (node->next == nullptr) {
            delete node;
            return nullptr;
        }
        node->next = __pop_back(node->next);
        return node;
    }

    void pop_back() {
        head = __pop_back(head);
    }

};

int main() {

}