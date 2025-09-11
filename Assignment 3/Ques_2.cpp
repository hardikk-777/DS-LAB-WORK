#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if (!isFull()) arr[++top] = c;
    }
    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0'; // empty case
    }
};

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    Stack st;
    for (int i = 0; str[i] != '\0'; i++) {
        st.push(str[i]);
    }

    cout << "Reversed: ";
    while (!st.isEmpty()) {
        cout << st.pop();
    }
    cout << "\n";

    return 0;
}
