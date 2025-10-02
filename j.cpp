#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> a;
vector<long long> order;

void build(int L, int R) {
    if (L > R) return;
    int mid = (L + R) / 2;     
    order.push_back(a[mid]);  
    build(L, mid - 1);         
    build(mid + 1, R);       
}

int main() {
    int N;
    cin >> N;
    int M = 1;              
    for (int i = 0; i < N; i++) M *= 2;
    M -= 1;
    a.reserve(M);
    for (int i = 0; i < M; i++) {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    build(0, M - 1);
    for (int i = 0; i < M; i++) {
        if (i) cout << ' ';
        cout << order[i];
    }
    cout << '\n';
    return 0;
}
