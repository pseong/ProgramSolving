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

ll dp[30][30];

ll f(int n, int k) {
    if (n == 0 && k == 0) return 1;
    if (k == 0) return 0;
    if (n < k) return 0;

    if (dp[n][k] != -1) return dp[n][k];
    ll ans = 0;
    ans += (n-1)*f(n-1,k) + f(n-1, k-1);
    return dp[n][k] = ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;
    ll a = 0;
    ll b = 0;
    for (int i=0; i<=m; i++) {
        a += f(n, i);
    }
    for (int i=0; i<=n; i++) {
        b += f(n, i);
    }
    ll g = gcd(a, b);
    cout << a/g << '/' << b/g << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}