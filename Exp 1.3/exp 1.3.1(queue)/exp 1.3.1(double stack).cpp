#include <iostream>
#include <stack>
using namespace std;
class Queue {
    stack<int> s1, s2;
public:
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool empty() {
        return s1.empty() && s2.empty();
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
