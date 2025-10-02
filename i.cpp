#include <iostream>
using namespace std;

struct Node {
    int key;
    int cnt;    
    Node *left, *right;
    Node(int k): key(k), cnt(1), left(nullptr), right(nullptr) {}
};

Node* findMin(Node* t) {
    while (t && t->left) t = t->left;
    return t;
}

Node* insert(Node* t, int x) {
    if (!t) return new Node(x);
    if (x < t->key) t->left  = insert(t->left, x);
    else if (x > t->key) t->right = insert(t->right, x);
    else t->cnt++;
    return t;
}

Node* eraseOne(Node* t, int x) {
    if (!t) return nullptr;
    if (x < t->key) t->left  = eraseOne(t->left, x);
    else if (x > t->key) t->right = eraseOne(t->right, x);
    else {
        if (t->cnt > 1) {           
            t->cnt--;
            return t;
        }
        if (!t->left && !t->right) {     
            delete t; 
            return nullptr;
        } else if (!t->left) {            
            Node* r = t->right; 
            delete t; 
            return r;
        } else if (!t->right) {        
            Node* l = t->left; 
            delete t; 
            return l;
        } else {                  
            Node* s = findMin(t->right);
            t->key = s->key;
            t->cnt = s->cnt;
            for (int i = 0; i < s->cnt; ++i)
                t->right = eraseOne(t->right, s->key);
            return t;
        }
    }
    return t;
}

int getCnt(Node* t, int x) {
    while (t) {
        if (x < t->key) t = t->left;
        else if (x > t->key) t = t->right;
        else return t->cnt;
    }
    return 0;
}

int main() {
    int Q;
    cin>>Q;
    Node* root = nullptr;
    for (int i = 0; i < Q; ++i) {
        string op; int x;
        cin >> op >> x;
        if (op == "insert") {
            root = insert(root, x);
        } else if (op == "delete") {
            root = eraseOne(root, x);
        } else if (op == "cnt") {
            cout << getCnt(root, x) << '\n';
        }
    }
    return 0;
}
