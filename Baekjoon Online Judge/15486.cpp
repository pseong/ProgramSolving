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

const int inf = 1000000000;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n+1), p(n+1), dp(n+1);
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    for (int i=1; i<=n; i++) {
        if (i + t[i] - 1 <= n) {
            dp[i+t[i]-1] = max(dp[i+t[i]-1], dp[i-1] + p[i]);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}