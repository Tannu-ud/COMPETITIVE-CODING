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
Node* oddEvenList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
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
        if (head == NULL)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    head = oddEvenList(head);
    cout << "Odd-Even Linked List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
