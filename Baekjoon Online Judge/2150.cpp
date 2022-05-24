#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
ll exgcd(ll a, ll b, ll &s, ll &t) { ll r1 = a, r2 = b, s1 = 1, s2 = 0, t1 = 0, t2 = 1; ll r, q; while (r2) { q = r1 / r2; r = r1 % r2; r1 = r2, r2 = r; s = s1 - q * s2; s1 = s2, s2 = s; t = t1 - q * t2; t1 = t2, t2 = t; } s = s1; t = t1; if (s <= 0) { s += b; t -= a; } return r1; }
ll inverse(ll A, ll B) { ll u, tmp; exgcd(A, B, u, tmp); return u; }
ll china(ll a, ll b, ll A, ll B, ll MOD) { ll s = 0; s = (s + MOD / A * inverse(MOD / A, A) * a) % MOD; s = (s + MOD / B * inverse(MOD / B, B) * b) % MOD; return s; }

vector<int> adj[10101];
vector<int> adjinv[10101];
bool chk[10101];
stack<int> st;
vector<vector<int>> scc;
vector<int> now;

void dfs(int x) {
    chk[x] = 1;
    for (int y : adj[x]) {
        if (chk[y]) continue;
        dfs(y);
    }
    st.push(x);
}

void dfs2(int x) {
    chk[x] = 1;
    now.push_back(x);
    for (int y : adjinv[x]) {
        if (chk[y]) continue;
        dfs2(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, e; cin >> n >> e;
    for (int i=0; i<e; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adjinv[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end());
        sort(adjinv[i].begin(), adjinv[i].end());
    }
    for (int i=1; i<=n; i++) {
        if (!chk[i]) dfs(i);
    }
    for (int i=1; i<=n; i++) chk[i] = 0;
    while (st.size()) {
        int x = st.top(); st.pop();
        if (chk[x]) continue;
        dfs2(x);
        scc.push_back(now);
        now.clear();
    }
    for (int i=0; i<scc.size(); i++) {
        sort(scc[i].begin(), scc[i].end());
    }
    sort(scc.begin(), scc.end());
    cout << scc.size() << '\n';
    for (vector<int>& v : scc) {
        for (int i=0; i<(int) v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << -1 << '\n';
    }
}