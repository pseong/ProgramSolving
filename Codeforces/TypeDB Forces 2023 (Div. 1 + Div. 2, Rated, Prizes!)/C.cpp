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
    ll n, s;
    cin >> n >> s;
    vector<ll> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    vector<pll> v2(n);
    for (int i=1; i<n-1; i++) {
        if (v[i] <= s) {
            v2[i].first = 0;
            v2[i].second = v[i];
        }
        else {
            v2[i].first = s;
            v2[i].second = v[i] - s;
        }
        if (v2[i].first > v2[i].second) swap(v2[i].first, v2[i].second);
    }
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[1][0] = v[0] * v2[1].first;
    dp[1][1] = v[0] * v2[1].second;
    for (int i=2; i<n-1; i++) {
        dp[i][0] = min(dp[i-1][0] + v2[i-1].second * v2[i].first, dp[i-1][1] + v2[i-1].first * v2[i].first);
        dp[i][1] = min(dp[i-1][0] + v2[i-1].second * v2[i].second, dp[i-1][1] + v2[i-1].first * v2[i].second);
    }
    cout << min(dp[n-2][0] + v2[n-2].second * v[n-1], dp[n-2][1] + v2[n-2].first * v[n-1]) << '\n';
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