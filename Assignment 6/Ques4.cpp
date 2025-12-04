#include <iostream>
using namespace std;

class Node {
public:
    char ch;
    Node* next;
    Node* prev;
    Node(char c): ch(c), next(nullptr), prev(nullptr) {}
};

class Doubly {
public:
    Node* head;
    Doubly(): head(nullptr) {}
    void append(char c) {
        Node* n = new Node(c);
        if (!head) { head = n; return; }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = n;
        n->prev = p;
    }
    bool isPalindrome() {
        if (!head) return true;
        Node* l = head;
        Node* r = head;
        while (r->next) r = r->next;
        while (l != r && l->prev != r) {
            if (l->ch != r->ch) return false;
            l = l->next;
            r = r->prev;
        }
        return true;
    }
};

int main() {
    Doubly d;
    string s;
    cin >> s;
    for (int i = 0; s[i]; ++i) d.append(s[i]);
    cout << (d.isPalindrome() ? "True" : "False") << '\n';
    return 0;
}
