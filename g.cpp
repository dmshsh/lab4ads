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
        } else if (x > cur->val) {           
            if (cur->right) cur = cur->right;
            else { cur->right = new Node(x); break; }
        } else {
            return;                        
        }
    }
}

int height(Node* root, int &diameter) {
    if (!root) return 0;
    int hl = height(root->left,  diameter); 
    int hr = height(root->right, diameter); 
    int through = hl + hr + 1;        
    if (through > diameter) diameter = through;
    return (hl > hr ? hl : hr) + 1;   
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        insertBST(root, x);
    }
    int diameter = 0;          
    height(root, diameter);
    cout << diameter << '\n';   
    return 0;
}
