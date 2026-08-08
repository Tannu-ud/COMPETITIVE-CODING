#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head;
    while (curr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
bool palindrome(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverse(slow);
    while (slow) {
        if (head->data != slow->data)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    Node *head = NULL, *tail = NULL;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* temp = new Node(x);
        if (!head)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    if (palindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}
