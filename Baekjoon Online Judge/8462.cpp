#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sqrtN = 350;

struct Q {
    int idx, i, j;
    bool operator < (Q& x) {
        if (i/sqrtN != x.i/sqrtN) {
            return i/sqrtN < x.i/sqrtN;
        }
        else return j < x.j;
    }
};

vector<Q> query;
int a[101010];
ll cnt[1010101];
ll ans[101010];
ll res;

void Add(int x) {
    res -= cnt[x]*cnt[x]*x;
    cnt[x]++;
    res += cnt[x]*cnt[x]*x;
}

void Sub(int x) {
    res -= cnt[x]*cnt[x]*x;
    cnt[x]--;
    res += cnt[x]*cnt[x]*x;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    for (int x=0; x<m; x++) {
        int i, j;
        cin >> i >> j;
        query.push_back({x, i, j});
    }
    sort(query.begin(), query.end());

    int s = query[0].i;
    int e = query[0].j;
    for (int i=s; i<=e; i++) {
        Add(a[i]);
    }
    ans[query[0].idx] = res;
    
    for (auto q : query) {
        int idx, i, j;
        idx = q.idx; i = q.i; j = q.j;
        while (s < i) Sub(a[s++]);
        while (s > i) Add(a[--s]);
        while (e < j) Add(a[++e]);
        while (e > j) Sub(a[e--]);
        ans[idx] = res;
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}