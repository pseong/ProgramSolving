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

ll dp[110][110][110];
const ll mod = 1000001;

ll f(int n, int m, int k) {
    if (k == 0) return 1;
    if (n <= 0 || m <= 0 || k <= 0) return 0;
    if (dp[n][m][k] != -1) {
        return dp[n][m][k];
    }
    ll ans = 0;
    ans += f(n-1, m, k);
    ans += f(n-1, m-1, k-1)*m;
    ans += f(n-1, m-2, k-2)*m*(m-1)/2;
    ans += f(n-2, m-1, k-2)*m*(n-1);
    ans %= mod;
    return dp[n][m][k] = ans;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    cout << f(n, m, k) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}