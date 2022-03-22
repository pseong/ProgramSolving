#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k, an[101010];

struct Seg {
    struct Node {
        int cnt;
    } tree[4040404];

    Node merge(Node left, Node right) {
        return {
            left.cnt + right.cnt
        };
    }

    int take(int node, int s, int e, int k) {
        if (s==e) {
            tree[node].cnt -= 1;
            return s;
        }
        int mid = (s+e)/2;
        Node left = tree[node*2];
        Node right = tree[node*2+1];
        int ret = 0;
        if (left.cnt >= k) {
            ret = take(node*2, s, mid, k);
        }
        else {
            ret = take(node*2+1, mid+1, e, k-left.cnt);
        }
        tree[node] = merge(tree[node*2], tree[node*2+1]);
        return ret;
    }

    void update(int node, int s, int e, int x, int p) {
        if (x<s || x>e) return;
        if (s==e) {
            tree[node].cnt += p;
            return;
        }
        int mid = (s+e)/2;
        Node left = tree[node*2];
        Node right = tree[node*2+1];
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what==1) {
            int b;
            cin >> b;
            cout << seg.take(1, 1, 1000000, b) << '\n';
        }
        else {
            int b, c;
            cin >> b >> c;
            seg.update(1, 1, 1000000, b, c);
        }
    }
}