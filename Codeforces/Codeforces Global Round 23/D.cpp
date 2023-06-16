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

vector<int> adj[202020];
ll s[202020];
map<ll, ll> dp[202020];

ll f(ll x, ll k) {
    if (dp[x].find(k) != dp[x].end()) return dp[x][k];
    int m = adj[x].size();
    if (k == 0 || m == 0) return k * s[x];
    if (m == 1) return dp[x][k] = f(adj[x][0], k) + s[x] * k;
    vector<ll> v;
    ll r = k * s[x];
    for (int y : adj[x]) {
        ll a = f(y, k/m);
        ll b = f(y, k/m+1);
        v.push_back(b - a);
        r += a;
    }
    sort(v.rbegin(), v.rend());
    for (int i=0; i<k%m; i++) r += v[i];
    return dp[x][k] = r;
}

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<=n; i++) adj[i].clear(), dp[i].clear();
    for (int i=2; i<=n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    for (int i=1; i<=n; i++) cin >> s[i];
    cout << f(1, k) << '\n';
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