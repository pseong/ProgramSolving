#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int insz = 1000;
const int outsz = 1010101/1000 + 10;

struct Q {
    int idx, i, j;
    bool operator < (const Q& right) const {
        if (i/insz != right.i/insz) return i < right.i;
        return j < right.j;
    }
};

int a[101010];
int ans[101010];
int bucket[outsz];
int cnt[1010101];
vector<Q> query;
list<int> deq[1010101];

void Add(int x, int op) {
    int len = 0;
    if (!deq[a[x]].empty()) {
        len = deq[a[x]].back() - deq[a[x]].front();
        cnt[len]--;
        bucket[len/insz]--;
    }
    if (!op) deq[a[x]].push_front(x);
    else deq[a[x]].push_back(x);
    len = deq[a[x]].back() - deq[a[x]].front();
    cnt[len]++;
    bucket[len/insz]++;
}

void Sub(int x, int op) {
    int len = deq[a[x]].back() - deq[a[x]].front();
    cnt[len]--;
    bucket[len/insz]--;
    if (!op) deq[a[x]].pop_front();
    else deq[a[x]].pop_back();
    if (!deq[a[x]].empty()) {
        len = deq[a[x]].back() - deq[a[x]].front();
        cnt[len]++;
        bucket[len/insz]++;
    }
}

int Cal() {
    for (int i=outsz-1; i>=0; i--) {
        if (bucket[i] == 0) continue;
        for (int j=insz-1; j>=0; j--) {
            if (cnt[i*insz+j] > 0) {
                return i*insz+j;
            } 
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        int b;
        cin >> b;
        a[i] = a[i-1] + b;
        a[i] %= k;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        query.push_back({i, x, y});
    }
    sort(query.begin(), query.end());

    int s = query[0].i;
    int e = query[0].j;
    for (int x=s; x<=e; x++) {
        Add(x, 1);
    }
    ans[query[0].idx] = Cal();

    for (int q=1; q<query.size(); q++) {
        while (s > query[q].i) Add(--s, 0);
        while (e < query[q].j) Add(++e, 1);
        while (s < query[q].i) Sub(s++, 0);
        while (e > query[q].j) Sub(e--, 1);
        ans[query[q].idx] = Cal();
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}