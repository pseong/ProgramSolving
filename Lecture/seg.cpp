#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000000;

long long tree[MAX*4 + 100];
long long lazy[MAX*4 + 100];
long long a[MAX + 10];

void propagation(int node, int s, int e) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node] * (e - s + 1);
    if (s != e) {
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

long long query(int node, int s, int e, int l, int r) {
    propagation(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[node];
    int mid = (s + e) / 2;
    long long left = query(node*2, s, mid, l, r);
    long long right = query(node*2+1, mid+1, e, l, r);
    return left + right;
}

void update(int node, int s, int e, int l, int r, long long x) {
    propagation(node, s, e);
    if (r < s || e < l) return;
    if (l <= s && e <= r) {
        lazy[node] += x;
        propagation(node, s, e);
        return;
    }
    int mid = (s + e) / 2;
    update(node*2, s, mid, l, r, x);
    update(node*2+1, mid+1, e, l, r, x);
    tree[node] = tree[node*2] + tree[node*2+1];
}

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    init(node*2, s, mid);
    init(node*2+1, mid+1, e);
    tree[node] = tree[node*2] + tree[node*2+1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    init(1, 1, n);
    
    for (int i=0; i<m+k; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
        else if (what == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}