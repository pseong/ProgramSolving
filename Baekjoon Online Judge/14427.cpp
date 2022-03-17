#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll seg[404040], an[101010];

ll init(int node, int s, int e) {
    if (s==e) return seg[node] = s;
    int mid = (s + e) / 2;
    int left = init(node*2, s, mid);
    int right = init(node*2+1, mid+1, e);
    seg[node] = left;
    if (an[left] > an[right]) seg[node] = right;
    return seg[node];
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    int left = init(node*2, s, mid);
    int right = init(node*2+1, mid+1, e);
    if (left==0) return seg[node] = left;
    if (right==0) return seg[node] = right;
    seg[node] = left;
    if (an[left] > an[right]) seg[node] = right;
    return seg[node];
}

ll update(int node, int s, int e, int l, int r, int x) {
    if (r < s || e < l) return seg[node];
    if (l <= s && e <= r) return seg[node];
    int mid = (s + e) / 2;
    int left = update(node*2, s, mid, l, r, x);
    int right = update(node*2+1, mid+1, e, l, r, x);
    if (left==0) return seg[node] = left;
    if (right==0) return seg[node] = right;
    seg[node] = left;
    if (an[left] > an[right]) seg[node] = right;
    return seg[node];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    init(1, 1, n);

    int m;
    cin >> m;

    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        if (a==1) {
            int i, v;
            cin >> i >> v;
            an[i] = v;
            update(1, 1, n, i, i, v);
        }
        else if (a==2) {
            cout << query(1, 1, n, 1, n) << '\n';
        }
    }
    return 0;
}