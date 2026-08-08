#include <iostream>
#include <stack>
using namespace std;
class Queue {
    stack<int> s;
public:
    void push(int x) {
        s.push(x);
    }
    int pop() {
        if (s.size() == 1) {
            int x = s.top();
            s.pop();
            return x;
        }
        int x = s.top();
        s.pop();
        int front = pop();
        s.push(x);
        return front;
    }
    int peek() {
        if (s.size() == 1)
            return s.top();
        int x = s.top();
        s.pop();
        int front = peek();
        s.push(x);
        return front;
    }
    bool empty() {
        return s.empty();
    }
};
int main() {
    Queue q;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }
    cout << "Front element: " << q.peek() << endl;
    cout << "Deleted element: " << q.pop() << endl;
    cout << "Front element: " << q.peek() << endl;
    return 0;
}
