#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

using namespace std;

ll an[500010];
vector<int> child[500010];
int cnt, in[500010], out[500010];

void dfs(int node) {
    in[node] = ++cnt;
    for (int x : child[node]) {
        dfs(x);
    }
    out[node] = cnt;
}

struct SegmentTree {
    ll seg[400010], lazy[400010];

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
} up, down;

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

    int dir = 0;
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int i, w;
            cin >> i >> w;
            if (dir == 0) down.update(1, 1, n, in[i], out[i], w);
            else up.update(1, 1, n, in[i], in[i], w);
        }
        else if (what == 2) {
            int i;
            cin >> i;
            cout << down.query(1, 1, n, in[i], in[i]) +
                    up.query(1, 1, n, in[i], out[i]) << '\n';
        }
        else if (what == 3) {
            dir ^= 1;
        }
    }
    return 0;
}