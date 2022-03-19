#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int insz = 300;

struct Q {
    int idx, s, e;
    bool operator < (const Q& right) const {
        if (s/insz != right.s/insz) return s < right.s;
        return e < right.e;
    }
};

int n, m, k;
int s, e;
int an[101010];
ll cnt[1 << 21], ans[101010], res;
vector<Q> query;

void addL(int x) {
    cnt[an[x]]++;
    res += cnt[k^an[x-1]];
}

void addR(int x) {
    res += cnt[k^an[x]];
    res += an[s-1] == (k^an[x]);
    cnt[an[x]]++;
}

void subL(int x) {
    res -= cnt[k^an[x-1]];
    cnt[an[x]]--;
}

void subR(int x) {
    cnt[an[x]]--;
    res -= cnt[k^an[x]];
    res -= an[s-1] == (k^an[x]);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        an[i] ^= an[i-1];
    }

    cin >> m;
    for (int i=0; i<m; i++) {
        int s, e;
        cin >> s >> e;
        query.push_back({i, s, e});
    }
    sort(query.begin(), query.end());

    s = query[0].s;
    e = query[0].e;
    for (int i=s; i<=e; i++) {
        addR(i);
    }
    ans[query[0].idx] = res;

    for (int q=1; q<m; q++) {
        while (s > query[q].s) addL(--s);
        while (e < query[q].e) addR(++e);
        while (s < query[q].s) subL(s++);
        while (e > query[q].e) subR(e--);
        ans[query[q].idx] = res;
    }

    for (int i=0; i<m; i++) {
        cout << ans[i] << '\n';
    }
}