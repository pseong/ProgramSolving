#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll exgcd(ll a, ll b, ll &s, ll &t) { ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1; ll r, q; while (r2) { q = r1 / r2; r = r1 % r2; r1 = r2, r2 = r; s = s1 - q * s2; s1 = s2, s2 = s; t = t1 - q * t2; t1 = t2, t2 = t; } s = s1; t = t1; if (s <= 0) { s += b; t -= a; } return r1; }
ll inverse(ll A, ll B) { ll u, tmp; exgcd(A, B, u, tmp); return u; }
ll china(ll a, ll b, ll A, ll B, ll MOD) { ll s = 0; s = (s + MOD / A * inverse(MOD / A, A) * a) % MOD; s = (s + MOD / B * inverse(MOD / B, B) * b) % MOD; return s; }

int p, n, cnt;
vector<pi> adj[202020];
int v[202020], e[202020];

void dfs(int x, int p, int d) {
    for (auto [y, i] : adj[x]) {
        if (y == p) continue;
        if (d == 1) {
            v[y] = cnt;
            e[i] = cnt ^ n;
        }
        else {
            v[y] = cnt ^ n;
            e[i] = cnt;
        }
        cnt++;
        dfs(y, x, !d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        cin >> p;
        n = 1<<p;
        for (int i=1;  i<=n; i++) {
            adj[i].clear();
            v[i] = 0;
            e[i] = 0;
        }
        for (int i=1; i<=n-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        cnt = 1;
        v[1] = n;
        dfs(1, 0, 1);
        cout << 1 << '\n';
        for (int i=1; i<=n; i++) cout << v[i] << ' '; cout << '\n';
        for (int i=1; i<=n-1; i++) cout << e[i] << ' '; cout << '\n';
    }
}