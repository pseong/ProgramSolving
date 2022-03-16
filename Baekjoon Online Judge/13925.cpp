#include <bits/stdc++.h>
using namespace std;
using ll=long long;

using namespace std;

ll seg[400010], lazy[2][400010], an[100010];
const int mod = 1000000007;

void propagation(int node, int s, int e) {
    if (!(lazy[0][node]==1 && lazy[1][node]==0)) {
        seg[node] = (seg[node] * lazy[0][node]) % mod;
        seg[node] = (seg[node] + (e-s+1) * lazy[1][node]) % mod;
        if (s!=e) {
            lazy[0][node*2] = lazy[0][node*2] * lazy[0][node];
            lazy[1][node*2] = lazy[1][node*2] * lazy[0][node] + lazy[1][node];
            lazy[0][node*2] %= mod; lazy[1][node*2] %= mod;
            
            lazy[0][node*2+1] = lazy[0][node*2+1] * lazy[0][node];
            lazy[1][node*2+1] = lazy[1][node*2+1] * lazy[0][node] + lazy[1][node];
            lazy[0][node*2+1] %= mod; lazy[1][node*2+1] %= mod;
        }
        lazy[0][node] = 1;
        lazy[1][node] = 0;
    }
}

ll init(int node, int s, int e) {
    if (s==e) return seg[node] = an[s];
    int mid = (s + e) / 2;
    return seg[node] = (init(node*2, s, mid) + init(node*2+1, mid+1, e)) % mod;
}

ll query(int node, int s, int e, int l, int r) {
    propagation(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return (query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r)) % mod;
}

ll update(int node, int s, int e, int l, int r, int v, int mul, int sum) {
    propagation(node, s, e);
    if (r < s || e < l) return seg[node];
    if (l <= s && e <= r) {
        lazy[0][node] *= mul; lazy[0][node] %= mod;
        lazy[1][node] *= mul; lazy[1][node] %= mod;
        lazy[1][node] += sum; lazy[1][node] %= mod;
        propagation(node, s, e);
        return seg[node];
    }
    int mid = (s + e) / 2;
    return seg[node] = (update(node*2, s, mid, l, r, v, mul, sum) + update(node*2+1, mid+1, e, l, r, v, mul, sum)) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }

    for (int i=1; i<=400005; i++) {
        lazy[0][i] = 1;
    }

    init(1, 1, n);

    cin >> m;
    for (int i=0; i<m; i++) {
        int a, x, y, v;
        cin >> a >> x >> y;
        if (a==1) {
            cin >> v;
            update(1, 1, n, x, y, v, 1, v);
        }
        else if (a==2) {
            cin >> v;
            update(1, 1, n, x, y, v, v, 0);
        }
        else if (a==3) {
            cin >> v;
            update(1, 1, n, x, y, v, 0, v);
        }
        else if (a==4) {
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}