#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[101010];
int n, m;
const ll leaf = 1000000000000000000LL;

struct Seg {
    struct Node {
        ll lval, rval, val, all;
    } tree[404040];

    Node merge(const Node& left, const Node& right) {
        return {
            max(left.lval, left.all + right.lval),
            max(right.rval, left.rval + right.all),
            max({left.val, right.val, left.rval + right.lval}),
            left.all + right.all,
        };
    }

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node].lval = an[s];
            tree[node].rval = an[s];
            tree[node].val = an[s];
            tree[node].all = an[s];
            return;
        }
        init(node*2, s, (s+e)/2);
        init(node*2+1, (s+e)/2+1, e);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r<l) return {-leaf, -leaf, -leaf, 0};
        if (e<l || r<s) return {-leaf, -leaf, -leaf, 0};
        if (l<=s && e<=r) return tree[node];
        Node left = query(node*2, s, (s+e)/2, l, r);
        Node right = query(node*2+1, (s+e)/2+1, e, l, r);
        return merge(left, right);
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    seg.init(1, 1, n);

    cin >> m;
    for (int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        cout << seg.query(1, 1, n, s, e).val << '\n';
    }
}