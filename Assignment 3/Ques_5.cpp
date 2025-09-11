#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    bool isEmpty() { return top == -1; }
};

int evaluatePostfix(char exp[]) {
    Stack st;

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            st.push(c - '0'); // convert char to int
        }
        else {
            int val2 = st.pop();
            int val1 = st.pop();
            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.pop();
}

int main() {
    char exp[100];
    cout << "Enter postfix expression (single digit operands): ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp) << "\n";
    return 0;
}
