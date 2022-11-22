#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

int parent[1010];

int find(int a) {
    if (parent[a] == parent[parent[a]]) return parent[a];
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) swap(a, b);
    parent[b] = a;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int n, m;
    cin >> n >> m;
    vector<ti> v;
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for (int i=0; i<=m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back({w, a, b});
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    for (int i=0; i<(int)v.size(); i++) {
        auto [c, a, b] = v[i];
        if (same(a, b)) continue;
        if (c == 0) cnt++;
        merge(a, b);
    }
    ll a = cnt * cnt;
    cnt = 0;
    sort(v.rbegin(), v.rend());
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for (int i=0; i<(int)v.size(); i++) {
        auto [c, a, b] = v[i];
        if (same(a, b)) continue;
        if (c == 0) cnt++;
        merge(a, b);
    }
    ll b = cnt * cnt;
    cout << abs(a - b);
}