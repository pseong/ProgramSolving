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

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    vector<ll> v(n + 1), cold(k + 1), hot(k + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=k; i++) cin >> cold[i];
    for (int i=1; i<=k; i++) cin >> hot[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 1e18));
    dp[1][0] = cold[v[1]];
    dp[1][1] = cold[v[1]];
    for (int i=2; i<=n; i++) {
        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + ((v[i] == v[i-1]) ? hot[v[i]] : cold[v[i]]);
        ll sum = 0;
        for (int j=i-1; j>=1; j--) {
            dp[i][1] = min(dp[i][1], ((v[j-1] == v[i]) ? hot[v[i]] : cold[v[i]]) + dp[j][1] + sum);
            if (v[j-1] == v[j]) sum += hot[v[j]];
            else sum += cold[v[j]];
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
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