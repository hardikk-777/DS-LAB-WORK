#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
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
    void printRepeatHead() {
        if (!head) return;
        Node* p = head;
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << head->data << '\n';
    }
};

int main() {
    Circular c;
    c.append(20);
    c.append(100);
    c.append(40);
    c.append(80);
    c.append(60);
    c.printRepeatHead();
    return 0;
}
