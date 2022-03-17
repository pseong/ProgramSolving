#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int seg[404040], lazy[404040], an[101010];

void propagation(int node, int s, int e) {
    if(lazy[node]) {
        seg[node] = lazy[node];
        if (s!=e) {
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node];
        }
        lazy[node] = 0;
    }
}

int query(int node, int s, int e, int l, int r) {
    propagation(node, s, e);
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return query(node*2, s, mid, l, r) | query(node*2+1, mid+1, e, l, r);
}

int update(int node, int s, int e, int l, int r, int t) {
    propagation(node, s, e);
    if (r < s || e < l) return seg[node];
    if (l <= s && e <= r) {
        lazy[node] = t;
        propagation(node, s, e);
        return seg[node];
    }
    int mid = (s + e) / 2;
    return seg[node] = update(node*2, s, mid, l, r, t) | update(node*2+1, mid+1, e, l, r, t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, t, q;
    cin >> n >> t >> q;

    update(1, 1, n, 1, n, 1);

    while(q--) {
        char c;
        int x, y, z;
        cin >> c >> x >> y;
        if (x > y) swap(x, y);
        if (c == 'C') {
            cin >> z;
            update(1, 1, n, x, y, 1<<(z-1));
        }
        else if (c == 'Q') {
            int q = query(1, 1, n, x, y);
            int ans = 0;
            while (q) {
                ans += (q & 1);
                q >>= 1;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}