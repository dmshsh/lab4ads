#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};
void insertBST(Node* &root, int x) {
    if (!root) { root = new Node(x); return; }
    Node* cur = root;
    while (true) {
        if (x < cur->val) {
            if (cur->left) cur = cur->left;
            else { cur->left = new Node(x); break; }
        } else {
            if (cur->right) cur = cur->right;
            else { cur->right = new Node(x); break; }
        }
    }
}
Node* findNode(Node* root, int x) {
    if (!root) return nullptr;
    if (root->val == x) return root;
    if (x < root->val) return findNode(root->left, x);
    return findNode(root->right, x);
}
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    int N;
    cin >> N;
    Node* root = nullptr;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        insertBST(root, x);
    }
    int target;
    cin >> target;

    Node* node = findNode(root, target);
    cout << countNodes(node) << "\n";

    return 0;
}
