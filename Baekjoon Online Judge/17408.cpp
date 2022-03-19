#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int an[101010];
int n, m;

struct Seg {
    struct Node {
        int first, second;
    } tree[404040];

    Node merge(Node left, Node right) {
        int a[4];
        a[0] = left.first;
        a[1] = left.second;
        a[2] = right.first;
        a[3] = right.second;
        sort(a, a+4);
        return {a[3], a[2]};
    }

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = {an[s], -1};
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node update(int node, int s, int e, int x, int p) {
        if (x<s || e<x) return tree[node];
        if (s==e) return tree[node] = {p, -1};
        int mid = (s+e)/2;
        Node left = update(node*2, s, mid, x, p);
        Node right = update(node*2+1, mid+1, e, x, p);
        return tree[node] = merge(left, right);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (e<l || r<s) return {-1, -1};
        if (l<=s && e<=r) return tree[node];
        int mid = (s+e)/2;
        Node left = query(node*2, s, mid, l, r);
        Node right = query(node*2+1, mid+1, e, l, r);
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
        int what;
        cin >> what;
        if (what==1) {
            int i, v;
            cin >> i >> v;
            seg.update(1, 1, n, i, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            auto node = seg.query(1, 1, n, l, r);
            cout << node.first + node.second << '\n';
        }
    }
}