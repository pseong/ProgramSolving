#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sqrtN;
struct Q {
    int idx, s, e;
    bool operator < (Q& x) {
        if (s/sqrtN != x.s/sqrtN) {
            return s/sqrtN < x.s/sqrtN;
        }
        else return e < x.e;
    }
};

struct Seg {
    struct Node {
        int cnt, l, r, val;
    } tree[120000];

    void init(int node, int s, int e) {
        if (s==e) {
            tree[node].l = s;
            tree[node].r = s;
            tree[node].val = 1000000000;
            return;
        }
        int mid = (s+e)/2;
        init(node*2, s, mid);
        init(node*2+1, mid+1, e);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    Node merge(Node left, Node right) {
        Node ret;
        ret.cnt = left.cnt + right.cnt;
        if (left.cnt) ret.l = left.l;
        else ret.l = right.l;
        if (right.cnt) ret.r = right.r;
        else ret.r = left.r;
        ret.val = min(left.val, right.val);
        if (left.cnt && right.cnt) {
            ret.val = min(ret.val, right.l-left.r);
        }
        return ret;
    }

    void update(int node, int s, int e, int x, int p) {
        if (x<s || x>e) return;
        if (s==e) {
            tree[node].cnt += p;
            tree[node].l = x;
            tree[node].r = x;
            tree[node].val = 1000000000;
            return;
        }
        int mid = (s+e)/2;
        update(node*2, s, mid, x, p);
        update(node*2+1, mid+1, e, x, p);
        tree[node] = merge(tree[node*2], tree[node*2+1]);
    }

    int query() {
        return tree[1].val;
    }
} seg;

vector<Q> qry;
int a[30303];
int ans[30303];
int n, m;

void add(int x) {
    seg.update(1, 1, n, x, 1);
}

void sub(int x) {
    seg.update(1, 1, n, x, -1);
}

int cal() {
    return seg.query();
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    sqrtN = sqrt(n);
    seg.init(1, 1, n);

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for (int x=0; x<m; x++) {
        int i, j;
        cin >> i >> j;
        qry.push_back({x, i, j});
    }

    sort(qry.begin(), qry.end());

    int s = qry[0].s;
    int e = qry[0].e;
    for (int i=s; i<=e; i++) {
        add(a[i]);
    }
    ans[qry[0].idx] = cal();

    for (int i=1; i<m; i++) {
        while (s > qry[i].s) add(a[--s]);
        while (e < qry[i].e) add(a[++e]);
        while (s < qry[i].s) sub(a[s++]);
        while (e > qry[i].e) sub(a[e--]);
        ans[qry[i].idx] = cal();
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
} 