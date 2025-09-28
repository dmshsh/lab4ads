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
        } else if (x > cur->val) {
            if (cur->right) cur = cur->right;
            else { cur->right = new Node(x); break; }
        } else return;
    }
}

void transform(Node* root, int &sumSoFar) {
    if (!root) return;
    transform(root->right, sumSoFar);
    sumSoFar += root->val;
    root->val = sumSoFar;
    transform(root->left, sumSoFar);
}

void printInOrder(Node* root) {
    if (!root) return;
    printInOrder(root->right);
    cout << root->val << " ";
    printInOrder(root->left);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insertBST(root, x);
    }
    int sumSoFar = 0;
    transform(root, sumSoFar);
    printInOrder(root);
    cout << "\n";
    return 0;
}
