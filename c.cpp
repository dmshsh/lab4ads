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
void printPreOrder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}
int main(){
    int n;
    cin>>n;
    Node *root=nullptr;
    for (int i=0;i<n;i++){
        int N;
        cin>>N;
        insertBST(root,N);
    }
    int target;
    cin>>target;
    Node* node = findNode(root, target);
    printPreOrder(node);
}