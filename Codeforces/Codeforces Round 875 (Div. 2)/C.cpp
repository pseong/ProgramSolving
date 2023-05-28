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

vector<pi> adj[202020];
int ans;

void dfs(int x, int p, int idx, int cnt) {
    ans = max(ans, cnt);
    for (auto [y, i] : adj[x]) {
        if (y == p) continue;
        if (i < idx) dfs(y, x, i, cnt + 1);
        else dfs(y, x, i, cnt);
    }
}

void solve(int CASE) {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) adj[i].clear();
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    ans = 1;
    dfs(1, 0, 0, 1);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}