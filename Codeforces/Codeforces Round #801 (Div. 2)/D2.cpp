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

int n;
vector<int> adj[202020];
int pre[202020], cnt[202020];

void dfs(int x, int p) {
    pre[x] = p;
    for (int y : adj[x]) {
        if (y == p) continue;
        dfs(y, x);
    }
}

void solve() {
    cin >> n;
    for (int i=0; i<=n; i++) {
        adj[i].clear();
        cnt[i] = 0;
        pre[i] = 0;
    }
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int mx = 0;
    for (int i=1; i<=n; i++) {
        mx = max(mx, (ll)adj[i].size());
    }
    if (mx == 0) {
        cout << 0 << '\n';
        return;
    }
    else if (mx <= 2) {
        cout << 1 << '\n';
        return;
    }
    int root = 1;
    for (int i=1; i<=n; i++) {
        if (adj[i].size() >= 3) root = i;
    }
    dfs(root, 0);
    for (int i=1; i<=n; i++) {
        if (adj[i].size() == 1) {
            int go = i;
            while (adj[go].size() <= 2) go = pre[go];
            cnt[go]++;
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (cnt[i] >= 1) ans += cnt[i]-1;
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