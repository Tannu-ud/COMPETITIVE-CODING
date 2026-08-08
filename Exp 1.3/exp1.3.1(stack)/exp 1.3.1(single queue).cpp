#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Deleted element: " << q.front() << endl;
            q.pop();
        }
    }
    void peek() {
        if (q.empty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element: " << q.front() << endl;
    }
};
int main() {
    Stack s;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        s.push(x);
    }
    s.peek();
    s.pop();
    s.peek();
    return 0;
}
