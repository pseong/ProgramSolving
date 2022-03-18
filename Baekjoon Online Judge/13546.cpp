#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sqrtN;

struct Q {
    int idx, i, j;
    bool operator < (Q& right) {
        if (i != right.i) return i < right.i;
        return j < right.j;
    }
};

int a[101010];
int table[101010];
vector<Q> query;
deque<int> cnt[101010];
int res;

void AddFront(int x) {
    int len = 0;
    if (cnt[a[x]].size() >= 2) {
        len = cnt[a[x]].back() - cnt[a[x]].front();
    }
    table[len]--;
    cnt[a[x]].push_front(x);
    if (cnt[a[x]].size() >= 2) {
        len = cnt[a[x]].back() - cnt[a[x]].front();
    }
    table[len]++;
    res = max(res, len);
}

void AddBack(int x) {
    int len = 0;
    if (cnt[a[x]].size() >= 2) {
        len = cnt[a[x]].back() - cnt[a[x]].front();
    }
    table[len]--;
    cnt[a[x]].push_back(x);
    if (cnt[a[x]].size() >= 2) {
        len = cnt[a[x]].back() - cnt[a[x]].front();
    }
    table[len]++;
    res = max(res, len);
}

void SubFront(int x) {
    int len = 0;
    if (cnt[a[x]].size() >= 2) {
        len = cnt[a[x]].back() - cnt[a[x]].front();
    }
    table[len]--;
    cnt[a[x]].pop_front();
    len = 0;
    if (cnt[a[x]].size() >= 2) {
        len = cnt[a[x]].back() - cnt[a[x]].front();
    }
    table[len]++;
}

void SubBack(int x) {

}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    sqrtN = sqrt(n);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int idx, x, y;
        cin >> idx >> x >> y;
        query.push_back({idx, x, y});
    }
    sort(query.begin(), query.end());

    int s = 0;
    int e = 0;
    for (auto q : query) {
        while (s < q.i) SubFront(s++);
        while (s > q.i) AddFront(--s);
        while (e < q.j) AddBack(++e);
        while (e > q.j) SubBack(e--);
    }
}