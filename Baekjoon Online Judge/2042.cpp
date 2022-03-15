#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

using namespace std;

ll seg[4000010], an[1000010];

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
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    return query(node*2, s, mid, l, r) + query(node*2+1, mid+1, e, l, r);
}

ll update(int node, int s, int e, int x, ll y) {
    if (x < s || e < x) return seg[node];
    if (s == e) return seg[node] = y;
    int mid = (s + e) / 2;
    return seg[node] = update(node*2, s, mid, x, y) + update(node*2+1, mid+1, e, x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }

    init(1, 1, n);

    for (int i=0; i<m+k; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        if (a==1) {
            update(1, 1, n, b, c);
        }
        else if (a==2) {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}