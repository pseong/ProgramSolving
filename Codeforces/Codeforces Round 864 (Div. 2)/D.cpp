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

int n, m;
ll v[101010], ip[101010], cnt[101010], parent[101010];
vector<int> adj[101010];

bool cmp(pll a, pll b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

using Cmp = integral_constant<decltype(&cmp), &cmp>;
set<pll, Cmp> c[101010];

void dfs(int x, int p) {
    ip[x] = v[x];
    cnt[x] = 1;
    for (auto y : adj[x]) {
        if (y == p) continue;
        parent[y] = x;
        dfs(y, x);
        cnt[x] += cnt[y];
        ip[x] += ip[y];
    }
}

void dfs2(int x, int p) {
    for (auto y : adj[x]) {
        if (y == p) continue;
        c[x].insert({cnt[y], y});
        dfs2(y, x);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int x;
            cin >> x;
            cout << ip[x] << '\n';
        }
        else {
            int x;
            cin >> x;
            if (c[x].empty()) continue;
            auto [d, y] = *c[x].begin();
            int p = parent[x];
            c[x].erase(c[x].begin());
            c[p].erase({cnt[x], x});
            parent[x] = y;
            parent[y] = p;
            ll diff = cnt[x] - cnt[y];
            cnt[x] -= cnt[y];
            cnt[y] += diff;
            c[p].insert({cnt[y], y});
            c[y].insert({cnt[x], x});
            ll ipdiff = ip[x] - ip[y];
            ip[x] -= ip[y];
            ip[y] += ipdiff;
        }
    }
}