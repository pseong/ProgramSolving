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
    vector<ll> dp(k + 1, 1e18);
    dp[0] = 0;
    for (int i=1; i<=n; i++) {
        vector<ll> ndp(k + 1, 1e18);
        if (v[i] == v[i-1]) {
            for (int j=0; j<=k; j++) {
                ndp[j] = min(ndp[j], dp[j] + hot[v[i]]);
            }
            for (int j=0; j<=k; j++) {
                if (j == v[i]) continue;
                ndp[v[i]] = min(ndp[v[i]], dp[j] + cold[v[i]]);
            }
            ndp[v[i]] = min(ndp[v[i]], dp[v[i]] + hot[v[i]]);
        }
        else {
            for (int j=0; j<=k; j++) {
                ndp[j] = min(ndp[j], dp[j] + cold[v[i]]);
            }
            for (int j=0; j<=k; j++) {
                if (j == v[i]) continue;
                ndp[v[i-1]] = min(ndp[v[i-1]], dp[j] + cold[v[i]]);
            }
            ndp[v[i-1]] = min(ndp[v[i-1]], dp[v[i]] + hot[v[i]]);
        }
        dp = ndp;
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
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