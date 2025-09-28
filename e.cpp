#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};
int maxWidth(Node* root) {
    if (root == nullptr) return 0;
    queue<Node*> q;
    q.push(root);
    int best = 0;
    while (!q.empty()) {
        int levelSize = (int)q.size();     
        if (levelSize > best) best = levelSize;

        for (int i = 0; i < levelSize; ++i) {
            Node* v = q.front(); q.pop();
            if (v->left  != nullptr) q.push(v->left);
            if (v->right != nullptr) q.push(v->right);
        }
    }
    return best;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<Node*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; ++i) nodes[i] = new Node(i);
    for (int i = 0; i < n - 1; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) nodes[x]->left  = nodes[y];
        else        nodes[x]->right = nodes[y];
    }
    Node* root = nodes[1];            
    cout << maxWidth(root) << "\n";      
    return 0;
}
