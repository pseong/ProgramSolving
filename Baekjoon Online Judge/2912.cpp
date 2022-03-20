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

vector<Q> qry;
int a[101010];
int cnt[101010];
int table[101010];
int ans[101010];
int res;

void add(int x) {
    if (cnt[x] != 0) table[cnt[x]]--;
    cnt[x]++;
    table[cnt[x]]++;
    res = max(res, cnt[x]);
}

void sub(int x) {
    table[cnt[x]]--;
    if (cnt[x] == res && !table[cnt[x]]) res--;
    cnt[x]--;
    table[cnt[x]]++;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    sqrtN = sqrt(n);

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
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
    ans[qry[0].idx] = res;

    for (int i=1; i<m; i++) {
        while (s > qry[i].s) add(a[--s]);
        while (e < qry[i].e) add(a[++e]);
        while (s < qry[i].s) sub(a[s++]);
        while (e > qry[i].e) sub(a[e--]);
        ans[qry[i].idx] = res;
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}