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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<ll> a(n + 1), cnt(n + 1), ans(n + 1);
    ll now = 0;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=0; i<n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    auto dfs = [&](auto self, int x, int p) -> void {
        cnt[x] = 0;
        for (int y : adj[x]) {
            if (y == p) continue;
            self(self, y, x);
            cnt[x] += cnt[y];
        }
        cnt[x]++;
        for (int y : adj[x]) {
            if (y == p) continue;
            now += cnt[y] * (a[x] ^ a[y]);
        }
    };
    dfs(dfs, 1, 0);
    ans[1] = now;
    auto dfs2 = [&](auto self, int x, int p, ll cur) -> void {
        for (int y : adj[x]) {
            if (y == p) continue;
            ll nxt = cur;
            nxt -= cnt[y] * (a[x] ^ a[y]);
            nxt += (n - cnt[y]) * (a[x] ^ a[y]);
            ans[y] = nxt;
            self(self, y, x, nxt);
        }
    };
    dfs2(dfs2, 1, 0, now);
    for (int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}