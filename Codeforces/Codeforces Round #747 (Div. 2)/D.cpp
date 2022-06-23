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

vector<pi> adj[202020];
int chk[202020], val[202020];
vector<vector<int>> groups;

void dfs(int x) {
    chk[x] = 1;
    groups.back().push_back(x);
    for (auto [y, w] : adj[x]) {
        if (chk[y] == 0) {
            dfs(y);
        }
    }
}

bool ok;
void dfs2(int x) {
    for (auto [y, w] : adj[x]) {
        if (val[y]) {
            if (w == 1 && val[x] != val[y]) {
                ok = false;
            }
            if (w == 0 && val[x] == val[y]) {
                ok = false;
            }
        }
        else {
            if (w == 1) {
                val[y] = val[x];
            }
            else {
                if (val[x] == 1) val[y] = 2;
                else val[y] = 1;
            }
            dfs2(y);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    groups.clear();
    for (int i=0; i<=n; i++) {
        adj[i].clear();
        chk[i] = 0;
        val[i] = 0;
    }
    for (int i=0; i<m; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "imposter") {
            adj[a].push_back({b, 0});
            adj[b].push_back({a, 0});
        }
        else {
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 1});
        }
    }

    for (int i=1; i<=n; i++) {
        if (chk[i] == 0) {
            int go = i;
            groups.push_back({});
            dfs(go);
        }
    }

    int ans = 0;
    for (auto& g : groups) {
        int go = g.front();
        val[go] = 1;
        ok = true;
        dfs2(go);
        if (!ok) {
            cout << -1 << '\n';
            return;
        }
        vector<int> cnt(3);
        for (int x : g) {
            cnt[val[x]]++;
        }
        ans += max(cnt[1], cnt[2]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}