#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sqrtN = 350;

struct BIT {
    ll tree[101010];
    ll sz = 100000;

    ll sum(int i) {
        ll ret = 0;
        while (i > 0) {
            ret += tree[i];
            i -= (i & -i);
        }
        return ret;
    }

    void update(int i, ll num) {
        while (i <= sz) {
            tree[i] += num;
            i += (i & -i);
        }
    }
} ft;

struct Q {
    int idx, s, e;
    bool operator < (const Q& r) const {
        if (s/sqrtN != r.s/sqrtN) return s < r.s;
        return e < r.e;
    }
};

int an[101010];
ll ans[101010], res;
int n, m, s, e;
vector<Q> qry;
vector<int> val;

void add(int x, int dir) {
    x = an[x];
    if (dir) res += ft.sum(ft.sz) - ft.sum(x);
    else res += ft.sum(x-1);
    ft.update(x, 1);
}

void sub(int x, int dir) {
    x = an[x];
    ft.update(x, -1);
    if (dir) res -= ft.sum(ft.sz) - ft.sum(x);
    else res -= ft.sum(x-1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        val.push_back(an[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    ft.sz = val.size() + 1;

    for (int i=1; i<=n; i++) {
        an[i] = 1 + lower_bound(val.begin(), val.end(), an[i]) - val.begin();
    }

    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        qry.push_back({i, x, y});
    }
    sort(qry.begin(), qry.end());

    s = qry[0].s;
    e = qry[0].e;
    int idx = qry[0].idx;
    for (int i=s; i<=e; i++) {
        add(i, 1);
    }
    ans[idx] = res;

    for (int i=1; i<m; i++) {
        while (s > qry[i].s) add(--s, 0);
        while (e < qry[i].e) add(++e, 1);
        while (s < qry[i].s) sub(s++, 0);
        while (e > qry[i].e) sub(e--, 1);
        ans[qry[i].idx] = res;
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}