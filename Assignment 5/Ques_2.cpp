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

int deleteKeyOccurrences(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            count++;
        } else curr = curr->next;
    }
    return count;
}

void print(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    push(head,1); push(head,3); push(head,1); push(head,2); 
    push(head,1); push(head,2); push(head,1);
    int key = 1;
    int count = deleteKeyOccurrences(head, key);
    cout << "Occurrences deleted: " << count << "\n";
    print(head);
}
