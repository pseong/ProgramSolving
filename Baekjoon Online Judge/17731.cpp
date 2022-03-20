#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sqrtN = 350;

struct Q {
    int idx, s, e;
    bool operator < (Q& x) {
        if (s/sqrtN != x.s/sqrtN) {
            return s/sqrtN < x.s/sqrtN;
        }
        else return e < x.e;
    }
};

vector<Q> qry;
vector<int> val;
int a[101010];
ll tmp[101010];
ll ans[101010];
int n, m, s, e, res, sz;

struct Seg {
    ll tree[1000000];
    int b = 1;
    void update(int x, ll diff) {
        int save = x;
        x += b;
        tree[x] += tmp[save] * diff;
        while (x > 1) {
            tree[x/2] = max(tree[x/2*2], tree[x/2*2+1]);
            x /= 2;
        }
    }
} seg;

void add(int x) {
    seg.update(x, 1);
}

void sub(int x) {
    seg.update(x, -1);
}

ll cal() {
    return seg.tree[1];
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i=1; i<=n; i++) {
        int idx = 1 + lower_bound(val.begin(), val.end(), a[i]) - val.begin();
        tmp[idx] = a[i];
        a[i] = idx;
    }
    sz = val.size();

    while (seg.b <= sz) {
        seg.b *= 2;
    }
    seg.b -= 1;

    for (int x=0; x<m; x++) {
        int i, j;
        cin >> i >> j;
        qry.push_back({x, i, j});
    }

    sort(qry.begin(), qry.end());

    s = qry[0].s;
    e = qry[0].e;
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