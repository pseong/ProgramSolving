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

ll adj[220][220];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    const ll inf = 1000000000000LL;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i != j) adj[i][j] = inf;
        }
    }
    for (int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    int k;
    cin >> k;
    vector<ll> v(k);
    for (int i=0; i<k; i++) {
        cin >> v[i];
    }
    vector<pll> can;
    ll ans = inf;
    for (int i=1; i<=n; i++) {
        ll cnt = 0;
        for (int j=0; j<k; j++) {
            cnt = max(cnt, adj[i][v[j]] + adj[v[j]][i]);
        }
        if (cnt >= inf) continue;
        ans = min(ans, cnt);
        can.push_back({i, cnt});
    }
    vector<ll> res;
    for (pll p : can) {
        if (p.second == ans) cout << p.first << ' ';
    }
}