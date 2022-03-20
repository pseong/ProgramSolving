#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sqrtN = 330;
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
int a[111111];
int tmp[111111];
int cnt[111111];
int table[sqrtN][111111];
int bucket[sqrtN];
int ans[111111];
int n, m, s, e, res;

void add(int x) {
    if (cnt[x] != 0) table[x/sqrtN][cnt[x]]--;
    cnt[x]++;
    table[x/sqrtN][cnt[x]]++;
    bucket[x/sqrtN] = max(bucket[x/sqrtN], cnt[x]);
}

void sub(int x) {
    table[x/sqrtN][cnt[x]]--;
    if (bucket[x/sqrtN]==cnt[x] && !table[x/sqrtN][cnt[x]]) {
        bucket[x/sqrtN]--;
    }
    cnt[x]--;
    table[x/sqrtN][cnt[x]]++;
}

int cal() {
    int idx = sqrtN;
    for (int i=sqrtN-1; i>=0; i--) {
        if (bucket[i] > bucket[idx]) {
            idx = i;
        }
    }

    int ans = -1;
    int val = -1;
    for (int i=0; i<sqrtN; i++) {
        int j = idx*sqrtN + i;
        if (val <= cnt[j]) {
            val = cnt[j];
            ans = j;
        }
    }
    return tmp[ans];
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
        int num = 1 + lower_bound(val.begin(), val.end(), a[i]) - val.begin();
        tmp[num] = a[i];
        a[i] = num;
    }

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