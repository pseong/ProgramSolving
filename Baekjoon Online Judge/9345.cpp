#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k, an[101010];

struct Seg {
    struct Node {
        int mx, mn;
    } tree[404040];

    Node merge(Node left, Node right) {
        return {
            max(left.mx, right.mx),
            min(left.mn, right.mn)
        };
    }

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = {an[s], an[s]};
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    void update(int node, int s, int e, int x, int p) {
        if (x<s || x>e) return;
        if (s==e) {
            tree[node] = {p, p};
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r<s || e<l) return {1, 100000};
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

    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            an[i] = i;
        }
        seg.init(1, 1, n);

        for (int i=0; i<k; i++) {
            int what;
            cin >> what;
            if (what == 1) {
                int l, r;
                cin >> l >> r;
                l++; r++;
                auto node = seg.query(1, 1, n, l, r);
                if (node.mx == r && node.mn == l) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            else {
                int a, b;
                cin >> a >> b;
                a++; b++;
                int one = an[a];
                int two = an[b];
                seg.update(1, 1, n, a, two);
                seg.update(1, 1, n, b, one);
                an[a] = two;
                an[b] = one;
            }
        }
    }
}