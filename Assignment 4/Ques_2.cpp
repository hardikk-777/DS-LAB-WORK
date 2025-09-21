#include <iostream>
using namespace std;
#define SIZE 5

class CQueue {
    int arr[SIZE];
    int front, rear;
public:
    CQueue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == SIZE - 1) || (rear + 1 == front); }
    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << "\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << "\n";
    }
    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front: " << arr[front] << "\n";
    }
};

int main() {
    CQueue cq;
    int choice, val;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; cq.enqueue(val); break;
            case 2: cq.dequeue(); break;
            case 3: cq.peek(); break;
            case 4: cq.display(); break;
        }
    } while (choice != 5);
}
