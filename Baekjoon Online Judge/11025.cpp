#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int n, k;

struct Seg {
    struct Node {
        int cnt;
    } tree[404040];

    Node merge(Node left, Node right) {
        return {
            left.cnt + right.cnt
        };
    }

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node] = {1};
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
            tree[node] = {p};
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node query_cnt(int node, int s, int e) {
        return tree[node];
    }

    int query_kth(int node, int s, int e, int k) {
        if (s==e) return s;
        int mid = (s+e)/2;
        Node left = tree[node*2];
        Node right = tree[node*2+1];
        if (k <= left.cnt) {
            return query_kth(node*2, s, mid, k);
        }
        else {
            return query_kth(node*2+1, mid+1, e, k-left.cnt);
        }
    }
} seg;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    seg.init(1, 1, n);

    vector<int> ans;
    int idx = k;
    for (int i=0; i<n; i++) {
        int cnt = seg.query_cnt(1, 1, n).cnt;
        if (cnt < idx) {
            idx %= cnt;
            if (!idx) idx += cnt;
        }
        int sel = seg.query_kth(1, 1, n, idx);
        seg.update(1, 1, n, sel, 0);
        ans.push_back(sel);
        idx += k-1;
    }

    cout << "<";
    for (int i=0; i<ans.size()-1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans.back() << '>';
}