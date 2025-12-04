#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

bool checkCircular(Node* head) {
    if (!head) return false;
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    Node* a = new Node(2);
    Node* b = new Node(4);
    Node* c = new Node(6);
    Node* d = new Node(7);
    Node* e = new Node(5);
    a->next = b; b->next = c; c->next = d; d->next = e; e->next = nullptr;
    cout << (checkCircular(a) ? "True" : "False") << '\n';
    return 0;
}
