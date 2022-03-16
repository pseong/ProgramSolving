#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

using namespace std;

ll seg[404040], lazy[404040], an[101010];
vector<int> v[101010];
int cnt, in[101010], out[101010];

void dfs(int node, int par) {
    in[node] = ++cnt;
    for (int x : v[node]) {
        if (x == par) continue;
        dfs(x, node);
    }
    out[node] = cnt;
}

void propagation(int node, int s, int e) {
    if(lazy[node]) {
        if ((e-s+1)%2 == 1) {
            seg[node] ^= lazy[node];
        }
        if (s!=e) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}

ll init(int node, int s, int e) {
    if (s==e) return seg[node] = an[s];
    int mid = (s + e) / 2;
    return seg[node] = init(node*2, s, mid) ^ init(node*2+1, mid+1, e);
}

ll query(int node, int s, int e, int l, int r) {
    propagation(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return query(node*2, s, mid, l, r) ^ query(node*2+1, mid+1, e, l, r);
}

ll update(int node, int s, int e, int l, int r, ll y) {
    propagation(node, s, e);
    if (r < l) return 0;
    if (r < s || e < l) return seg[node];
    if (l <= s && e <= r) {
        lazy[node] ^= y;
        propagation(node, s, e);
        return seg[node];
    }
    int mid = (s + e) / 2;
    return seg[node] = update(node*2, s, mid, l, r, y) ^ update(node*2+1, mid+1, e, l, r, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=2; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);

    for (int i=1; i<=n; i++) {
        cin >> an[in[i]];
    }

    init(1, 1, n);

    while(m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int x;
            cin >> x;
            cout << query(1, 1, n, in[x], out[x]) << '\n';
        }
        else {
            int x;
            ll y;
            cin >> x >> y;
            update(1, 1, n, in[x], out[x], y);
        }
    }
    return 0;
}