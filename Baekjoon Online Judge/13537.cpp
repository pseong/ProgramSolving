#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[101010];
vector<int> seg[404040];

void init(int node, int s, int e) {
    if (s==e) {
        seg[node].push_back(an[s]);
        return;
    }
    int mid = (s + e) / 2;
    init(node*2, s, mid);
    init(node*2+1, mid+1, e);
    seg[node] = seg[node*2];
    seg[node].insert(seg[node].end(), seg[node*2+1].begin(), seg[node*2+1].end());
    sort(seg[node].begin(), seg[node].end());
}

int query(int node, int s, int e, int l, int r, int k) {
    if (e<l || r<s) return 0;
    if (l<=s && e<=r) {
        return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);
    }
    int mid = (s + e) / 2;
    return query(node*2, s, mid, l, r, k) + query(node*2+1, mid+1, e, l, r, k);
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
    while (m--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(1, 1, n, i, j, k) << '\n';
    }
}