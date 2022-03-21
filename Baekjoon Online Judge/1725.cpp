#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k;
ll an[101010];

struct Seg {
    struct Node {
        ll mn, mn_idx;
    } tree[404040];

    Node merge(Node left, Node right) {
        if (left.mn > right.mn) {
            swap(left.mn, right.mn);
            swap(left.mn_idx, right.mn_idx);
        }
        return left;
    }

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = {an[s], s};
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r<s || e<l) return {1000000000000000000, -1};
        if (l<=s && e<=r) return tree[node];
        int mid = (s+e)/2;
        Node left = query(node*2, s, mid, l, r);
        Node right = query(node*2+1, mid+1, e, l, r);
        return merge(left, right);
    }

} seg;

ll ans = 0;
void f(int s, int e) {
    if (e<s) return;
    if (s==e) {
        ans = max(ans, an[s]);
        return;
    }
    int mn_idx = seg.query(1, 1, n, s, e).mn_idx;
    ans = max(ans, an[mn_idx]*(e-s+1LL));
    f(s, mn_idx-1);
    f(mn_idx+1, e);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    seg.init(1, 1, n);
    
    f(1, n);
    cout << ans;
}