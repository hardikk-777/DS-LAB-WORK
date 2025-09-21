#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }
    void insertAtBeginning(int val) {
        Node* n = new Node{val, head};
        head = n;
    }
    void insertAtEnd(int val) {
        Node* n = new Node{val, nullptr};
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
    void insertBefore(int key, int val) {
        if (!head) return;
        if (head->data == key) { insertAtBeginning(val); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* n = new Node{val, temp->next};
            temp->next = n;
        }
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (temp) {
            Node* n = new Node{val, temp->next};
            temp->next = n;
        }
    }
    void deleteBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void deleteEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }
    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key) { deleteBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (temp->next) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Found at position " << pos << "\n";
                return;
            }
            temp = temp->next; pos++;
        }
        cout << "Not found\n";
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int choice, val, key;
    do {
        cout << "\n1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter\n"
             << "5.DelBeg 6.DelEnd 7.DelNode 8.Search 9.Display 10.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; list.insertAtBeginning(val); break;
            case 2: cin >> val; list.insertAtEnd(val); break;
            case 3: cin >> key >> val; list.insertBefore(key, val); break;
            case 4: cin >> key >> val; list.insertAfter(key, val); break;
            case 5: list.deleteBeginning(); break;
            case 6: list.deleteEnd(); break;
            case 7: cin >> key; list.deleteNode(key); break;
            case 8: cin >> key; list.search(key); break;
            case 9: list.display(); break;
        }
    } while (choice != 10);
}
