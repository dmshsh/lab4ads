#include <iostream>

using namespace std;

int gcd(int a, int b) {
    for (int i = min(a, b); i >= 1; --i) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

int gcd2(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd2(b, a % b);
}


int gcd1(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b)
            a = a % b;
        else
            b = b % a;        
    }


    return a + b;
}
// 
class Node {
    public:
    int data;
    Node *next, *prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
    public:
    Node *tail, *front;
    
    LinkedList() {
        tail = NULL;
        front = NULL;
    }

    void push_back(int data) {
        Node *node = new Node(data);
        if (tail == NULL) {
            tail = node;
            front = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void push_front(int data) {
        Node *node = new Node(data);
        if (front == NULL) {
            tail = node;
            front = node;
        } else {
            front->prev = node;
            node->next = front;
            front = node;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL)
                tail->next = NULL;
            else 
                front = NULL;
        }
    }

    void pop_front() {
        if (front != NULL) {
            front = front->next;
            if (front != NULL)
                front->prev = NULL;
            else
                tail = NULL;
        }
    }

    void del_node(Node *node) {
        if (node == tail)
            pop_back();
        else if (node == front) 
            pop_front();
        else {
            Node *a = node->prev;
            Node *b = node->next;
            a->next = b;
            b->prev = a;
        }
    }

    void print() {
        Node *node = front;
        while (node != NULL) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << endl;
    }

    Node* find_node(int data) {
        Node *node = front;
        while (node != NULL) {
            if (node->data == data)
                return node;
            node = node->next; 
        }
        return NULL;
    }

    void insert_node(Node *node1, int data) {
        Node *node = new Node(data);
        if (node1 == tail) 
            push_back(data);
        else {
            Node *node2 = node1->next;
            node1->next = node;
            node->prev = node1;
            node->next = node2;
            node2->prev = node;
        }
    }
};
// 
class Node {
    public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class Stack {
    public:
    Node *top;
    int sz;

    Stack() {
        top = NULL;
        sz = 0;
    }

    void push(int data) {
        Node *node = new Node(data);
        node->next = top;
        top = node;
        sz++;
    }

    void pop() {
        if (top != NULL) {
            top = top->next;
            sz--;
        }
    }

    int size() {
        return this->sz;
    }

    bool empty() {
        return (sz == 0);
    }
};
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    if (!node) return head;
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; ++i) cur = cur->next;

    if (cur) {
        node->next = cur->next;
        cur->next  = node;
    }
    return head;
}

Node* remove(Node* head, int p){
    if (!head) return head;
    if (p == 0) {
        Node* nxt = head->next;
        delete head;
        return nxt;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1 && cur; ++i) cur = cur->next;
    if (cur && cur->next) {
        Node* del = cur->next;
        cur->next = del->next;
        delete del;
    }
    return head;
}

Node* replace(Node* head, int p1, int p2){
   
    if (!head || p1 == p2) return head;

    
    Node* moved = nullptr;
    if (p1 == 0) {
        moved = head;
        head  = head->next;
    } else {
        Node* cur = head;
        for (int i = 0; i < p1 - 1 && cur; ++i) cur = cur->next;
        moved = cur->next;             
        cur->next = moved->next;
    }
    moved->next = nullptr;

  
    if (p2 == 0) {
        moved->next = head;
        head = moved;
        return head;
    } else {
        Node* cur = head;
        for (int i = 0; i < p2 - 1 && cur; ++i) cur = cur->next;
        moved->next = cur->next;
        cur->next = moved;
        return head;
    }
}

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* cur  = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur  = nxt;
    }
    return prev;
}

void print(Node* head){
    if (!head) { cout << -1 << "\n"; return; }
    Node* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << ' ';
        cout << cur->val;
        first = false;
        cur = cur->next;
    }
    cout << "\n";
}

Node* cyclic_left(Node* head, int x){
    if (!head || !head->next || x == 0) return head;


    int n = 1;
    Node* tail = head;
    while (tail->next) { tail = tail->next; ++n; }

    int k = x % n;
    if (k == 0) return head;

    Node* cutPrev = head;
    for (int i = 1; i < k; ++i) cutPrev = cutPrev->next; 
    Node* newHead = cutPrev->next;

    cutPrev->next = nullptr;
    tail->next = head;

    return newHead;
}

Node* cyclic_right(Node* head, int x){
    if (!head || !head->next || x == 0) return head;


    int n = 1;
    Node* tail = head;
    while (tail->next) { tail = tail->next; ++n; }

    int k = x % n;
    if (k == 0) return head;


    return cyclic_left(head, n - k);
}

int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; if(!(cin >> command)) break;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}