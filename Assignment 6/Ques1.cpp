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

    void insertFirst(int v) {
        Node* n = new Node(v);
        if (head) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    void insertLast(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; return; }
        Node* p = head;
        while (p->next) p = p->next;
        p->next = n;
        n->prev = p;
    }

    void insertAfter(int target, int v) {
        Node* p = head;
        while (p && p->data != target) p = p->next;
        if (!p) { cout << "Target not found\n"; return; }
        Node* n = new Node(v);
        n->next = p->next;
        n->prev = p;
        if (p->next) p->next->prev = n;
        p->next = n;
    }

    void insertBefore(int target, int v) {
        Node* p = head;
        while (p && p->data != target) p = p->next;
        if (!p) { cout << "Target not found\n"; return; }
        Node* n = new Node(v);
        n->next = p;
        n->prev = p->prev;
        if (p->prev) p->prev->next = n;
        else head = n;
        p->prev = n;
    }

    void removeValue(int v) {
        Node* p = head;
        while (p && p->data != v) p = p->next;
        if (!p) { cout << "Node not found\n"; return; }
        if (p->prev) p->prev->next = p->next;
        else head = p->next;
        if (p->next) p->next->prev = p->prev;
        delete p;
        cout << "Deleted " << v << '\n';
    }

    void search(int v) {
        Node* p = head;
        int pos = 1;
        while (p) {
            if (p->data == v) { cout << "Found " << v << " at " << pos << '\n'; return; }
            p = p->next; pos++;
        }
        cout << "Not found\n";
    }

    int size() {
        int c = 0; Node* p = head;
        while (p) { c++; p = p->next; }
        return c;
    }

    void display() {
        Node* p = head;
        cout << "DLL: ";
        while (p) {
            cout << p->data;
            if (p->next) cout << " <-> ";
            p = p->next;
        }
        cout << '\n';
    }
};

class Circular {
public:
    Node* head;
    Circular(): head(nullptr) {}

    void insertFirst(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; n->next = n; return; }
        Node* p = head;
        while (p->next != head) p = p->next;
        n->next = head;
        p->next = n;
        head = n;
    }

    void insertLast(int v) {
        Node* n = new Node(v);
        if (!head) { head = n; n->next = n; return; }
        Node* p = head;
        while (p->next != head) p = p->next;
        p->next = n;
        n->next = head;
    }

    void insertAfter(int target, int v) {
        if (!head) { cout << "List empty\n"; return; }
        Node* p = head;
        do {
            if (p->data == target) {
                Node* n = new Node(v);
                n->next = p->next;
                p->next = n;
                return;
            }
            p = p->next;
        } while (p != head);
        cout << "Target not found\n";
    }

    void insertBefore(int target, int v) {
        if (!head) { cout << "List empty\n"; return; }
        Node* p = head;
        Node* prev = nullptr;
        do {
            if (p->data == target) {
                Node* n = new Node(v);
                n->next = p;
                if (prev) prev->next = n;
                else {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    last->next = n;
                    head = n;
                }
                return;
            }
            prev = p;
            p = p->next;
        } while (p != head);
        cout << "Target not found\n";
    }

    void removeValue(int v) {
        if (!head) { cout << "List empty\n"; return; }
        Node* p = head;
        Node* prev = nullptr;
        do {
            if (p->data == v) {
                if (prev) prev->next = p->next;
                else {
                    Node* last = head;
                    while (last->next != head) last = last->next;
                    if (head == head->next) head = nullptr;
                    else {
                        last->next = head->next;
                        head = head->next;
                    }
                }
                delete p;
                cout << "Deleted " << v << '\n';
                return;
            }
            prev = p;
            p = p->next;
        } while (p != head);
        cout << "Node not found\n";
    }

    void search(int v) {
        if (!head) { cout << "List empty\n"; return; }
        Node* p = head;
        int pos = 1;
        do {
            if (p->data == v) { cout << "Found " << v << " at " << pos << '\n'; return; }
            p = p->next; pos++;
        } while (p != head);
        cout << "Not found\n";
    }

    int size() {
        if (!head) return 0;
        int c = 0; Node* p = head;
        do { c++; p = p->next; } while (p != head);
        return c;
    }

    void display() {
        if (!head) { cout << "CLL empty\n"; return; }
        Node* p = head;
        cout << "CLL: ";
        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << head->data << '\n';
    }
};

int main() {
    Doubly dll;
    Circular cll;
    int mainChoice = -1;
    while (true) {
        cout << "1 Doubly 2 Circular 0 Exit\n";
        cin >> mainChoice;
        if (mainChoice == 0) break;
        if (mainChoice == 1) {
            int opt = -1;
            while (opt != 8) {
                cout << "1 insFirst 2 insLast 3 insAfter 4 insBefore 5 del 6 search 7 disp 8 back\n";
                cin >> opt;
                if (opt == 1) { int v; cin >> v; dll.insertFirst(v); }
                else if (opt == 2) { int v; cin >> v; dll.insertLast(v); }
                else if (opt == 3) { int t,v; cin >> t >> v; dll.insertAfter(t,v); }
                else if (opt == 4) { int t,v; cin >> t >> v; dll.insertBefore(t,v); }
                else if (opt == 5) { int v; cin >> v; dll.removeValue(v); }
                else if (opt == 6) { int v; cin >> v; dll.search(v); }
                else if (opt == 7) dll.display();
            }
        } else if (mainChoice == 2) {
            int opt = -1;
            while (opt != 8) {
                cout << "1 insFirst 2 insLast 3 insAfter 4 insBefore 5 del 6 search 7 disp 8 back\n";
                cin >> opt;
                if (opt == 1) { int v; cin >> v; cll.insertFirst(v); }
                else if (opt == 2) { int v; cin >> v; cll.insertLast(v); }
                else if (opt == 3) { int t,v; cin >> t >> v; cll.insertAfter(t,v); }
                else if (opt == 4) { int t,v; cin >> t >> v; cll.insertBefore(t,v); }
                else if (opt == 5) { int v; cin >> v; cll.removeValue(v); }
                else if (opt == 6) { int v; cin >> v; cll.search(v); }
                else if (opt == 7) cll.display();
            }
        }
    }
    cout << "Exit\n";
    return 0;
}
