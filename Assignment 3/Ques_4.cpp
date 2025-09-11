#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
};

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void infixToPostfix(char infix[]) {
    Stack st;
    char postfix[MAX];
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix[k++] = c; // operand directly
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[k++] = st.pop();
            }
            st.pop(); // remove '('
        }
        else { // operator
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek())) {
                postfix[k++] = st.pop();
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()) {
        postfix[k++] = st.pop();
    }
    postfix[k] = '\0';

    cout << "Postfix: " << postfix << "\n";
}

int main() {
    char infix[100];
    cout << "Enter infix expression: ";
    cin >> infix;
    infixToPostfix(infix);
    return 0;
}
