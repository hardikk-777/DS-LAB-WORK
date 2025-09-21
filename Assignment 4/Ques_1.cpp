#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == SIZE - 1; }
    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) front = rear = -1;
        else front++;
    }
    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << "\n";
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
        }
    } while (choice != 5);
}
