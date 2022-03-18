#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int insz = 350;

struct Q {
    int idx, i, j;
    bool operator < (const Q& right) const {
        if (i/insz != right.i/insz) return i < right.i;
        return j < right.j;
    }
};

int a[101010];
ll ans[101010];
ll seg[101010];
int n, k, m;
ll res;
vector<Q> query;

void update(ll i, ll val) {
    while (i <= 100000) {
        seg[i] += val;
        i += i & -i;
    }
}

ll quer(ll i) {
    if (i < 1) return 0;
    if (i > 100000) i = 100000;
    ll ret = 0;
    while (i > 0) {
        ret += seg[i];
        i -= i & -i;
    }
    return ret;
}

void Add(int x) {
    res += quer(x+k) - quer(x-k-1);
    update(x, 1);
}

void Sub(int x) {
    update(x, -1);
    res -= quer(x+k) - quer(x-k-1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        query.push_back({i, --x, --y});
    }
    sort(query.begin(), query.end());

    int s = query[0].i;
    int e = query[0].j;
    for (int x=s; x<=e; x++) {
        Add(a[x]);
    }
    ans[query[0].idx] = res;

    for (int q=1; q<query.size(); q++) {
        while (s > query[q].i) Add(a[--s]);
        while (e < query[q].j) Add(a[++e]);
        while (s < query[q].i) Sub(a[s++]);
        while (e > query[q].j) Sub(a[e--]);
        ans[query[q].idx] = res;
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}