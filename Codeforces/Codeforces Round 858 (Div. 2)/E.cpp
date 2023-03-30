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

const int maxn = 101010;
const int sqrtn = 320;
const int inf = 1e9;

int n, q, depth[101010], h[101010], cnt[101010];
int a[101010], p[101010];
ll dp[101010][350];
vector<int> adj[101010];

void dfs(int x, int d) {
    h[x] = ++cnt[d];
    depth[x] = d;
    for (int y : adj[x]) {
        dfs(y, d + 1);
    }
}

ll ask(int x, int y) {
    if (x == 0 && y == 0) return 0;
    if (cnt[depth[y]] < sqrtn && dp[x][h[y]]) return dp[x][h[y]];
    ll ans = ask(p[x], p[y]) + 1LL * a[x] * a[y];
    if (cnt[depth[y]] < sqrtn) dp[x][h[y]] = ans;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=2; i<=n; i++) {
        cin >> p[i];
        adj[p[i]].push_back(i);
    }
    dfs(1, 0);
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << ask(x, y) << '\n';
    }
}