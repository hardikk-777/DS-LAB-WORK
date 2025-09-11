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

bool isBalanced(char expr[]) {
    Stack st;
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (st.isEmpty()) return false;
            char top = st.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return st.isEmpty();
}

int main() {
    char expr[100];
    cout << "Enter expression: ";
    cin >> expr;

    if (isBalanced(expr))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

