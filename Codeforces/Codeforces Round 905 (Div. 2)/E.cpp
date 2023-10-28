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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int n, t;
    cin >> n >> t;
    vector<vector<pi>> adj(n + 1);
    for (int i=1; i<=t; i++) {
        int m;
        cin >> m;
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
    }
    int k;
    cin >> k;
    vector<int> v(k + 1);
    vector<vector<int>> pos(t + 1);
    for (int i=1; i<=k; i++) {
        cin >> v[i];
        pos[v[i]].push_back(i);
    }
    const int inf = 1e9;
    vector<int> chk(n + 1, inf);
    pqg<pi> q;
    q.emplace(0, 1);
    chk[1] = 0;
    while (q.size()) {
        auto [d, x] = q.top();
        q.pop();
        if (chk[x] != d) continue;
        for (auto [y, t] : adj[x]) {
            auto it = upper_bound(pos[t].begin(), pos[t].end(), d);
            if (it == pos[t].end()) continue;
            if (*it >= chk[y]) continue;
            chk[y] = *it;
            q.emplace(*it, y);
        }
    }
    if (chk[n] == inf) cout << -1 << '\n';
    else cout << chk[n] << '\n';
}