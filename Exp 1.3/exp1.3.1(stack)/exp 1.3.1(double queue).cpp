#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Deleted element: " << q1.front() << endl;
            q1.pop();
        }
    }
    void peek() {
        if (q1.empty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element: " << q1.front() << endl;
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
