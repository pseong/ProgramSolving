#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    struct Node {
        ll cnt;
    } tree[4040404];

    Node merge(Node left, Node right) {
        return {left.cnt + right.cnt};
    }

    void update(int node, int s, int e, int x, int p) {
        if (x<s || e<x) return;
        if (s==e) {
            tree[node].cnt += p;
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r<l) return {0};
        if (r<s || e<l) return {0};
        if (l<=s && e<=r) return tree[node];
        int mid = (s+e)/2;
        Node left = query(node*2, s, mid, l, r);
        Node right = query(node*2+1, mid+1, e, l, r);
        return merge(left, right);
    }

} seg;

int n, k;
ll ans;
int ord[1010101];

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        a++;
        ord[a] = i;
    }
    for (int i=1; i<=n; i++) {
        int b;
        cin >> b;
        b++;
        ans += seg.query(1, 1, 1000001, ord[b]+1, 1000001).cnt;
        seg.update(1, 1, 1000001, ord[b], 1);
    }
    cout << ans;
}