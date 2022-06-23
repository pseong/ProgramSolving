#include <bits/stdc++.h>
#define int long long
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

vector<int> adj[101010];
int v[101010];

int cnt;
int dfs(int x, int p, int to) {
    int xo = v[x];
    for (int y : adj[x]) {
        if (y == p) continue;
        xo ^= dfs(y, x, to);
    }
    if (xo == to) {
        cnt++;
        return 0;
    }
    return xo;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<=n; i++) {
        adj[i].clear();
        v[i] = 0;
    }
    cnt = 0;
    int xo = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        xo ^= v[i];
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (xo == 0) {
        yes();
        return;
    }
    if (k == 2) {
        no();
        return;
    }
    dfs(1, 0, xo);
    if (cnt >= 2) yes();
    else no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}