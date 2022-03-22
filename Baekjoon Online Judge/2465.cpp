#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, an[101010], s[101010], ans[101010];

struct Seg {
    struct Node {
        int val, cnt;
    } tree[404040];

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node].val = an[s];
            tree[node].cnt = 1;
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node].cnt = tree[node*2].cnt + tree[node*2+1].cnt;
    }

    void update(int node, int s, int e, int x, int p) {
        if (x<s || x>e) return;
        if (s==e) {
            tree[node].cnt += p;
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node].cnt = tree[node*2].cnt + tree[node*2+1].cnt;
    }

    pair<int, int> queryKth(int node, int s, int e, int k) {
        if (s==e) return {s, tree[node].val};
        int mid = (s+e)/2;
        if (tree[node*2].cnt >= k) {
            return queryKth(node*2, s, mid, k);
        }
        else {
            return queryKth(node*2+1, mid+1, e, k-tree[node*2].cnt);
        }
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    sort(an+1, an+1+n);
    seg.init(1, 1, n);

    for (int i=n; i>=1; i--) {
        int x, val;
        tie(x, val) = seg.queryKth(1, 1, n, s[i]+1);
        ans[i] = val;
        seg.update(1, 1, n, x, -1);
    }

    for (int i=1; i<=n; i++) {
        cout << ans[i] << '\n';
    }
}