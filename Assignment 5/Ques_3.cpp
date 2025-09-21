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

int findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    Node* head = nullptr;
    for (int i = 5; i >= 1; i--) push(head, i);
    cout << "Middle: " << findMiddle(head) << "\n";
}
