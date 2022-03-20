#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sqrtN = 300;
struct Q {
    int idx, s, e;
    bool operator < (Q& x) {
        if (s/sqrtN != x.s/sqrtN) {
            return s < x.s;
        }
        else return e < x.e;
    }
};

vector<Q> qry;
vector<int> val;
int a[505050];
int cnt[505050];
int ans[505050];
int n, m, res;

void add(int x) {
    if (cnt[x]==2) res--;
    cnt[x]++;
    if (cnt[x]==2) res++;
}

void sub(int x) {
    if (cnt[x]==2) res--;
    cnt[x]--;
    if (cnt[x]==2) res++;
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
        a[i] = 1 + lower_bound(val.begin(), val.end(), a[i]) - val.begin();
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