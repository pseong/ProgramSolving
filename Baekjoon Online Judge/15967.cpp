#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll seg[4000010], lazy[4000010], an[1000010];

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

    int n, q1, q2;
    cin >> n >> q1 >> q2;

    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }

    init(1, 1, n);

    for (int i=0; i<q1+q2; i++) {
        int a;
        cin >> a;
        if (a==1) {
            int b, c;
            cin >> b >> c;
            cout << query(1, 1, n, b, c) << '\n';
        }
        else if (a==2) {
            int b, c;
            ll d;
            cin >> b >> c >> d;
            update(1, 1, n, b, c, d);
        }
    }
    return 0;
}