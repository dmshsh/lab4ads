#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insertBST(Node* &root, int x) {
    if (!root) {
        root = new Node(x);
        return;
    }
    Node* cur = root;
    while (true) {
        if (x < cur->val) {
            if (cur->left != nullptr) {
                cur = cur->left;
            } else {
                cur->left = new Node(x);
                break;
            }
        } else {
            if (cur->right != nullptr) {
                cur = cur->right;
            } else {
                cur->right = new Node(x);
                break;
            }
        }
    }
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
    vector<long long> sums;  
    queue<pair<Node*, int>> q;   
    if (root != nullptr) {
        q.push(make_pair(root, 0));
    }
    while (!q.empty()) {
        pair<Node*, int> front = q.front();
        q.pop();
        Node* node = front.first;
        int level = front.second;
        if ((int)sums.size() <= level) {
            sums.push_back(0);
        }
        sums[level] += node->val;
        if (node->left != nullptr) {
            q.push(make_pair(node->left, level + 1));
        }
        if (node->right != nullptr) {
            q.push(make_pair(node->right, level + 1));
        }
    }
    int levels = (int)sums.size();
    cout << levels << "\n";
    for (int i = 0; i < levels; i++) {
        if (i > 0) cout << " ";
        cout << sums[i];
    }
    cout << "\n";
    return 0;
}
