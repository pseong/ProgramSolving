#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sqrtN;
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
int cnt[1010101];
int ans[101010];
int res;

void Add(int x) {
    if (x != 0 && !cnt[x]) res++;
    cnt[x]++;
}

void Sub(int x) {
    cnt[x]--;
    if (cnt[x] == 0) res--;
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
        query.push_back({x, i, j});
    }

    sort(query.begin(), query.end());

    int s = 0;
    int e = 0;
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