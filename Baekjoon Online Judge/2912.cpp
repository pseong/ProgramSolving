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
int a[303030];
int cnt[10101];
pair<int, int> ans[303030];
int s, e, n, m, c;

void add(int x) {
    cnt[x]++;
}

void sub(int x) {
    cnt[x]--;
}

pair<int, int> cal() {
    int len = (e-s+1)/2;
    for (int i=1; i<=10000; i++) {
        if (cnt[i] > len) {
            return {1, i};
        }
    }
    return {0, 0};
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    sqrtN = sqrt(n);

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    cin >> m;
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
        if (ans[i].first == 1) {
            cout << "yes " << ans[i].second << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }
}