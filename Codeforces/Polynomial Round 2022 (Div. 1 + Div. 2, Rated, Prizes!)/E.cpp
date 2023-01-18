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
int n, d, a[202020], b[202020], dp[202020][2];
ll ans = 0;

void go(int x, int p) {
    if (a[x]) dp[x][0] = 0;
    if (b[x]) dp[x][1] = 0;
    for (int y : adj[x]) {
        if (y == p) continue;
        go(y, x);
        if (dp[y][0] >= 0 || dp[y][1] + 1 > d) ans += 2;
        if (dp[y][1] >= 0 || dp[y][0] + 1 > d) ans += 2;
        if (dp[y][0] != -1) dp[x][0] = max(dp[x][0], dp[y][0] + 1);
        if (dp[y][1] != -1) dp[x][1] = max(dp[x][1], dp[y][1] + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof dp);
    cin >> n >> d;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int c;
    cin >> c;
    while (c--) {
        int d;
        cin >> d;
        a[d] = 1;
    }
    cin >> c;
    while (c--) {
        int d;
        cin >> d;
        b[d] = 1;
    }
    go(1, 0);
    cout << ans << '\n';
}