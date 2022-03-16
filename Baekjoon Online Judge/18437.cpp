#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

using namespace std;

ll seg[400010], lazy[400010];
vector<int> child[100010];
int cnt, in[100010], out[100010];

void dfs(int node) {
    in[node] = ++cnt;
    for (int x : child[node]) {
        dfs(x);
    }
    out[node] = cnt;
}

void propagation(int node, int s, int e) {
    if(lazy[node]) {
        int x = lazy[node] - 1;
        seg[node] = (e-s+1)*x;
        if (s!=e) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

ll init(int node, int s, int e) {
    if (s==e) {
        seg[node] = 1;
        return seg[node];
    }
    int mid = (s + e) / 2;
    return seg[node] = init(node*2, s, mid) + init(node*2+1, mid+1, e);
}

ll query(int node, int s, int e, int l, int r) {
    propagation(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
}

ll update(int node, int s, int e, int l, int r, ll x) {
    propagation(node, s, e);
    if (r < l) return 0;
    if (r < s || e < l) return seg[node];
    if (l <= s && e <= r) {
        lazy[node] = x;
        propagation(node, s, e);
        return seg[node];
    }
    int mid = (s + e) / 2;
    return seg[node] = update(node*2, s, mid, l, r, x) + update(node*2+1, mid+1, e, l, r, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;;

    int par;
    cin >> par;
    for (int i=2; i<=n; i++) {
        cin >> par;
        child[par].push_back(i);
    }

    dfs(1);
    init(1, 1, n);

    cin >> m;
    while(m--) {
        int what, i;
        cin >> what >> i;
        if (what == 1) {
            update(1, 1, n, in[i]+1, out[i], 2);
        }
        else if (what == 2) {
            update(1, 1, n, in[i]+1, out[i], 1);
        }
        else {
            cout << query(1, 1, n, in[i]+1, out[i]) << '\n';
        }
    }
    return 0;
}