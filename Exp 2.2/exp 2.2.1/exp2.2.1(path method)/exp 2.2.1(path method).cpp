#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
    if (!root) return false;

    path.push_back(root);

    if (root == node) return true;

    if (findPath(root->left, node, path) ||
        findPath(root->right, node, path))
        return true;

    path.pop_back();
    return false;
}

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> path1, path2;

    findPath(root, p, path1);
    findPath(root, q, path2);

    TreeNode* ans = nullptr;

    for (int i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] == path2[i])
            ans = path1[i];
        else
            break;
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    TreeNode* p = root->left;   // 5
    TreeNode* q = root->right;  // 1

    cout << "LCA = " << LCA(root, p, q)->val;

    return 0;
}
