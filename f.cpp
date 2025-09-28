#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
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


int countTriangles(Node* root) {
    if (!root) return 0;
    int here = (root->left != nullptr && root->right != nullptr) ? 1 : 0;
    return here + countTriangles(root->left) + countTriangles(root->right);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        insertBST(root, x);
    }
    cout << countTriangles(root) << '\n';
    return 0;
}
