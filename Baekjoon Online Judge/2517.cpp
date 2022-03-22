#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    struct Node {
        ll cnt;
    } tree[2000000];

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

int n, k, an[505050];
vector<int> val;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        val.push_back(an[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i=1; i<=n; i++) {
        an[i] = 1 + lower_bound(val.begin(), val.end(), an[i]) - val.begin();
    }

    for (int i=1; i<=n; i++) {
        cout << i-seg.query(1, 1, n, 1, an[i]).cnt << '\n';
        seg.update(1, 1, n, an[i], 1);
    }
}