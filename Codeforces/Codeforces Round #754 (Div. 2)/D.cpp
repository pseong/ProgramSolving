#include <bits/stdc++.h>
#define int long long
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

vector<int> adj[202020];
vector<int> bi[2];
vector<int> part[20];

void color(int x, int p, int c) {
    bi[c].push_back(x);
    for (int y : adj[x]) {
        if (y == p) continue;
        color(y, x, 1-c);
    }
}

void solve() {
    int n; cin >> n;
    for (int i=0; i<=n; i++) adj[i].clear();
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    color(1, 0, 0);
    int limit = 1;
    for (int i=1; i<=n; i++) {
        if (i == 1LL << limit) {
            limit++;
        }
        part[limit].push_back(i);
    }

    vector<int> ans(n+1);
    for (int l=19; l>=1; l--) {
        int p = 0;
        if (bi[p].size() < part[l].size()) p = 1;
        while (part[l].size()) {
            ans[bi[p].back()] = part[l].back();
            part[l].pop_back();
            bi[p].pop_back();
        }
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}