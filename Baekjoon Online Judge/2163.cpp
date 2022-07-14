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

int dp[330][330];
const int inf = 1000000000;

int f(int n, int m) {
    if (n == 1 && m == 1) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    int ans = inf;
    for (int i=1; i<n; i++) {
        ans = min(ans, 1 + f(i, m) + f(n-i, m));
    }
    for (int i=1; i<m; i++) {
        ans = min(ans, 1 + f(n, i) + f(n, m-i));
    }
    return dp[n][m] = ans;
}

void solve() {
    int n, m;
    cin >> n >> m;

    memset(dp, -1, sizeof dp);
    cout << f(n, m) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}