#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, an[505050], bn[505050], cn[505050];
int inf = 1e9;

struct Seg {
    int tree[2020202];

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = inf;
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    void update(int node, int s, int e, int x, int p) {
        if (x<s || x>e) return;
        if (s==e) {
            tree[node]= p;
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node] = min(tree[node*2], tree[node*2+1]);
    }

    int query(int node, int s, int e, int l, int r) {
        if (r<s || e<l) return inf;
        if (l<=s && e<=r) return tree[node];
        int mid = (s+e)/2;
        return min(query(node*2, s, mid, l, r), query(node*2+1, mid+1, e, l, r));
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for (int i=1; i<=n; i++) {
        int a; cin >> a;
        bn[a] = i;
    }
    for (int i=1; i<=n; i++) {
        int a; cin >> a;
        cn[a] = i;
    }
    seg.init(1, 1, n);

    int ans = 0;
    for (int i=1; i<=n; i++) {
        int num = an[i];
        if (seg.query(1, 1, n, 1, bn[num]) > cn[num]) ans++;
        seg.update(1, 1, n, bn[num], cn[num]);
    }
    cout << ans;
}