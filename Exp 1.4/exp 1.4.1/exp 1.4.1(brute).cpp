#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
bool palindrome(Node* head) {
    vector<int> a;
    while (head) {
        a.push_back(head->data);
        head = head->next;
    }
    int i = 0, j = a.size() - 1;
    while (i < j) {
        if (a[i] != a[j])
            return false;
        i++;
        j--;
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
