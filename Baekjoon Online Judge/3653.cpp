#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[101010], n, m;
struct Seg {
    int tree[404040], lazy[404040];
    
    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = an[s];
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
    }

    void lazy_update(int node, int s, int e) {
        if (lazy[node]) {
            tree[node] += (s+e-1)*lazy[node];
            if (s!=e) {
                tree[node*2] += lazy[node];
                tree[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r, int p) {
        lazy_update(node, s, e);
        if (r<s || e<s) return;
        if (l<=s && e<=r) {
            lazy[node] += p;
            lazy_update(node, s, e);
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, l, r, p);
        update(node*2+1, mid+1, e, l, r, p);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    int query(int node, int s, int e, int x) {
        lazy_update(node, s, e);
        if (x<s || x>e) return 0;
        if (s==e) return tree[node];
        int mid = (s+e)/2;
        return query(node*2, s, mid, x) + query(node*2+1, mid+1, e, x);
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            an[i] = n-i;
        }
        memset(seg.lazy, 0, sizeof seg.lazy);
        seg.init(1, 1, n);
        for (int i=0; i<m; i++) {
            int x;
            cin >> x;
            int ans = seg.query(1, 1, n, x);
            cout << ans << ' ';
        }
        cout << '\n';
    }
}