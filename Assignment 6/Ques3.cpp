#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int v): data(v), next(nullptr), prev(nullptr) {}
};

class Doubly {
public:
    Node* head;
    Doubly(): head(nullptr) {}
    void append(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = n;
        n->prev = p;
    }
    int size() {
        int c = 0; Node* p = head;
        while (p) { c++; p = p->next; }
        return c;
    }
};

class Circular {
public:
    Node* head;
    Circular(): head(nullptr) {}
    void append(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; n->next = n; return; }
        Node* p = head;
        while (p->next != head) p = p->next;
        p->next = n;
        n->next = head;
    }
    int size() {
        if (!head) return 0;
        int c = 0; Node* p = head;
        do { c++; p = p->next; } while (p != head);
        return c;
    }
};

int main() {
    Doubly d;
    Circular c;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> x; d.append(x); }
    cin >> n;
    for (int i = 0; i < n; ++i) { cin >> x; c.append(x); }
    cout << d.size() << '\n' << c.size() << '\n';
    return 0;
}
