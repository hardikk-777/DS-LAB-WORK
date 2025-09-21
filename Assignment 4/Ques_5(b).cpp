#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) { cout << "Empty\n"; return; }
        q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};

int main() {
    Stack s;
    s.push(5); s.push(10); s.push(15);
    cout << s.top() << "\n";
    s.pop();
    cout << s.top() << "\n";
}
