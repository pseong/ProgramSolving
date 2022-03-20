#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sqrtN = 2000;

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
int a[1010101];
int cnt[1010101];
int ans[1010101];
int n, m, res;

void Add(int x) {
    if (!cnt[x]) res++;
    cnt[x]++;
}

void Sub(int x) {
    if (cnt[x] == 1) res--;
    cnt[x]--;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    val.resize(n);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        val[i-1] = a[i];
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    for (int i=1; i<=n; i++) {
        a[i] = 1 + lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    }

    cin >> m;
    qry.resize(m);
    for (int x=0; x<m; x++) {
        cin >> qry[x].s >> qry[x].e;
        qry[x].idx = x;
    }
    sort(qry.begin(), qry.end());

    int s = qry[0].s;
    int e = qry[0].e;
    for (int i=s; i<=e; i++) {
        Add(a[i]);
    }
    ans[qry[0].idx] = res;
    
    for (int i=1; i<m; i++) {
        while (s > qry[i].s) Add(a[--s]);
        while (e < qry[i].e) Add(a[++e]);
        while (s < qry[i].s) Sub(a[s++]);
        while (e > qry[i].e) Sub(a[e--]);
        ans[qry[i].idx] = res;
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}