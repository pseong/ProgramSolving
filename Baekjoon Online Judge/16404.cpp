#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

using namespace std;

ll seg[2000010], lazy[2000010], input[500010], an[500010];
vector<int> child[500010];
int cnt, in[500010], out[500010];

void dfs(int node) {
    in[node] = ++cnt;
    for (int x : child[node]) {
        dfs(x);
    }
    out[node] = cnt;
}

void propagation(int node, int s, int e) {
    if(lazy[node]) {
        seg[node] += (e-s+1)*lazy[node];
        if (s!=e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll init(int node, int s, int e) {
    if (s==e) {
        seg[node] = an[s];
        return seg[node];
    }
    int mid = (s + e) / 2;
    seg[node] = init(node*2, s, mid) + init(node*2+1, mid+1, e);
    return seg[node];
}

ll query(int node, int s, int e, int l, int r) {
    propagation(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
}

ll update(int node, int s, int e, int l, int r, ll diff) {
    propagation(node, s, e);
    if (r < l) return 0;
    if (r < s || e < l) return seg[node];
    if (l <= s && e <= r) {
        lazy[node] += diff;
        propagation(node, s, e);
        return seg[node];
    }
    int mid = (s + e) / 2;
    return seg[node] = update(node*2, s, mid, l, r, diff) + update(node*2+1, mid+1, e, l, r, diff);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int par;
    cin >> par;
    for (int i=2; i<=n; i++) {
        cin >> par;
        child[par].push_back(i);
    }

    dfs(1);
    init(1, 1, n);

    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int i, w;
            cin >> i >> w;
            update(1, 1, n, in[i], out[i], w);
        }
        else {
            int i;
            cin >> i;
            cout << query(1, 1, n, in[i], in[i]) << '\n';
        }
    }
    return 0;
}