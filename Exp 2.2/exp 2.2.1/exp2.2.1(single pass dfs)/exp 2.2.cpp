#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* createTree() {
    int x;
    cin >> x;

    if (x == -1)
        return NULL;

    Node* root = new Node(x);

    cout << "Enter left child of " << x << ": ";
    root->left = createTree();

    cout << "Enter right child of " << x << ": ";
    root->right = createTree();

    return root;
}

Node* LCA(Node* root, int p, int q) {

    if (root == NULL || root->data == p || root->data == q)
        return root;

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {
    cout << "Enter root (-1 for NULL): ";
    Node* root = createTree();

    int p, q;

    cout << "Enter p: ";
    cin >> p;

    cout << "Enter q: ";
    cin >> q;

    Node* ans = LCA(root, p, q);

    cout << "LCA = " << ans->data;

    return 0;
}
