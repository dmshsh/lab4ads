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

int main() {
    int N, M;
    cin >> N >> M;
    Node* root = nullptr;
    for (int i = 0, x; i < N; ++i) {
        cin >> x;
        insertBST(root, x);
    }

    while (M--) {
        string path;
        cin >> path;
        Node* cur = root;
        bool ok = true;
        for (char c : path) {
            if (!cur) { ok = false; break; }
            if (c == 'L') cur = cur->left;
            else cur = cur->right;
        }
        cout << ((ok && cur) ? "YES\n" : "NO\n");
    }
    return 0;
}
