#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sq = 400;
int b_sz;
int sqrtN;

struct Q {
    int idx, i, j;
    bool operator < (const Q& right) const {
        if (i/sqrtN != right.i/sqrtN) return i < right.i;
        return j < right.j;
    }
};

ll ans;
int n, m, s, e;

void add(int x, int op, vector<list<int>>& deq, vector<int> &a, vector<int> &cnt, vector<int> &bucket) {
    int len = 0;
    int ab = a[x];
    if (!deq[a[x] + n].empty()) {
        len = deq[a[x] + n].back() - deq[a[x] + n].front();
        cnt[len]--;
        bucket[len/sq]--;
    }
    if (!op) deq[a[x] + n].push_front(x);
    else deq[a[x] + n].push_back(x);
    len = deq[a[x] + n].back() - deq[a[x] + n].front();
    cnt[len]++;
    bucket[len/sq]++;
}

void sub(int x, int op, vector<list<int>>& deq, vector<int> &a, vector<int> &cnt, vector<int> &bucket) {
    int len = deq[a[x] + n].back() - deq[a[x] + n].front();
    cnt[len]--;
    bucket[len/sq]--;
    if (!op) deq[a[x] + n].pop_front();
    else deq[a[x] + n].pop_back();
    if (!deq[a[x] + n].empty()) {
        len = deq[a[x] + n].back() - deq[a[x] + n].front();
        cnt[len]++;
        bucket[len/sq]++;
    }
}

int cal(vector<int> &cnt, vector<int> &bucket) {
    for (int i=b_sz; i>=0; i--) {
        if (bucket[i] == 0) continue;
        for (int j=sq-1; j>=0; j--) {
            if (cnt[i*sq+j] > 0) {
                return i*sq+j;
            } 
        }
    }
    return 0;
}

void solve() {
    ans = 0; n = 0; m = 0; s = 0; e = 0;

    cin >> n;
    sqrtN = sqrt(n);
    
    vector<list<int>> deq(n*2 + 1);
    vector<int> a(n + 1);
    vector<int> cnt((n+sq)/sq*sq);
    vector<Q> query;
    b_sz = n / sq + 1;
    vector<int> bucket(b_sz + 1);

    for (int i=1; i<=n; i++) {
        int b;
        cin >> b;
        a[i] = a[i-1] + b;
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        query.push_back({i, x, y});
    }
    sort(query.begin(), query.end());

    s = query[0].i;
    e = query[0].j;
    for (int x=s; x<=e; x++) {
        add(x, 1, deq, a, cnt, bucket);
    }
    ans += cal(cnt, bucket);

    for (int q=1; q<query.size(); q++) {
        while (s > query[q].i) add(--s, 0, deq, a, cnt, bucket);
        while (e < query[q].j) add(++e, 1, deq, a, cnt, bucket);
        while (s < query[q].i) sub(s++, 0, deq, a, cnt, bucket);
        while (e > query[q].j) sub(e--, 1, deq, a, cnt, bucket);
        ans += cal(cnt, bucket);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
}