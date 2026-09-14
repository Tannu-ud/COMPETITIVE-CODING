#include <iostream>
#include <vector>
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

    cout << "Left child of " << x << ": ";
    root->left = createTree();

    cout << "Right child of " << x << ": ";
    root->right = createTree();

    return root;
}

void inorder(Node* root, vector<Node*>& v) {
    if (!root)
        return;

    inorder(root->left, v);
    v.push_back(root);
    inorder(root->right, v);
}

Node* successor(Node* root, int p) {
    vector<Node*> v;
    inorder(root, v);

    for (int i = 0; i < v.size(); i++) {
        if (v[i]->data == p) {
            if (i + 1 < v.size())
                return v[i + 1];
            return NULL;
        }
    }

    return NULL;
}

int main() {
    cout << "Enter root (-1 for NULL): ";
    Node* root = createTree();

    int p;
    cout << "Enter p: ";
    cin >> p;

    Node* ans = successor(root, p);

    if (ans)
        cout << "Inorder Successor = " << ans->data;
    else
        cout << "No Inorder Successor";

    return 0;
}
