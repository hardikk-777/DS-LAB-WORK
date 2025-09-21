#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node*& head, int val) {
    Node* n = new Node{val, head};
    head = n;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(Node* head) {
    while (head) { cout << head->data << "->"; head = head->next; }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    for (int i = 4; i >= 1; i--) push(head, i);
    head = reverse(head);
    print(head);
}
