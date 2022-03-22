#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[202020], n, m, idx[202020];
struct Seg {
    int tree[808080], lazy[808080];
    
    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = an[s];
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node] = tree[node*2] + tree[node*2+1];
    }

    void lazy_update(int node, int s, int e) {
        if (lazy[node]) {
            tree[node] += (e-s+1)*lazy[node];
            if (s!=e) {
                tree[node*2] += lazy[node];
                tree[node*2+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int s, int e, int l, int r, int p) {
        lazy_update(node, s, e);
        if (r<l) return;
        if (r<s || e<l) return;
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

    int query(int node, int s, int e, int l, int r) {
        lazy_update(node, s, e);
        if (r<l) return 0;
        if (r<s || e<l) return 0;
        if (l<=s && e<=r) return tree[node];
        int mid = (s+e)/2;
        return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        memset(seg.lazy, 0, sizeof seg.lazy);
        memset(seg.tree, 0, sizeof seg.tree);
        memset(an, 0, sizeof an);
        memset(idx, 0, sizeof idx);

        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            an[m+i] = 1;
            idx[i] = m+i;
        }
        seg.init(1, 1, n+m);

        int space = m;
        for (int i=0; i<m; i++) {
            int x;
            cin >> x;
            cout << seg.query(1, 1, n+m, 1, idx[x]-1) << ' ';
            seg.update(1, 1, n+m, idx[x], idx[x], -1);
            seg.update(1, 1, n+m, space, space, 1);
            idx[x] = space;
            space--;
        }
        cout << '\n';
    }
}