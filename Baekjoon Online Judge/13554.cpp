#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int insz = 350;

struct Q {
    int idx, i, j, k;
    bool operator < (const Q& right) const {
        if (i/insz != right.i/insz) return i < right.i;
        return j < right.j;
    }
};

struct BIT {
    ll tree[101010];
    void update(ll i, ll val) {
        while (i <= 100000) {
            tree[i] += val;
            i += i & -i;
        }
    }

    ll quer(ll i) {
        if (i < 1) return 0;
        if (i > 100000) i = 100000;
        ll ret = 0;
        while (i > 0) {
            ret += tree[i];
            i -= i & -i;
        }
        return ret;
    }
};

int a[101010], b[101010];
ll ans[101010];
BIT A, B;
int n, m;
vector<Q> query;

void Add(int x) {
    A.update(a[x], 1);
    B.update(b[x], 1);
}

void Sub(int x) {
    A.update(a[x], -1);
    B.update(b[x], -1);
}

ll Cal(int k) {
    ll ret = 0;
    int sqrtK = sqrt(k);
    for (int i=1; i<=sqrtK; i++) {
        ret += (A.quer(i)-A.quer(i-1))*B.quer(k/i);
        ret += (B.quer(i)-B.quer(i-1))*A.quer(k/i);
    }
    return ret - A.quer(sqrtK)*B.quer(sqrtK);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        query.push_back({i, x, y, k});
    }
    sort(query.begin(), query.end());

    int s = query[0].i;
    int e = query[0].j;
    for (int x=s; x<=e; x++) {
        Add(x);
    }
    ans[query[0].idx] = Cal(query[0].k);

    for (int q=1; q<query.size(); q++) {
        while (s > query[q].i) Add(--s);
        while (e < query[q].j) Add(++e);
        while (s < query[q].i) Sub(s++);
        while (e > query[q].j) Sub(e--);
        ans[query[q].idx] = Cal(query[q].k);
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}