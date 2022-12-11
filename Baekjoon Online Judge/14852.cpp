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

ll dp[1010101], pref[1010101];
const ll mod = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    pref[0] = 1;
    pref[1] = 3;
    for (int i=2; i<=n; i++) {
        dp[i] += dp[i-1] * 2 + dp[i-2] * 3;
        if (i-3 >= 0) dp[i] += pref[i-3] * 2;
        dp[i] %= mod;
        pref[i] = pref[i-1] + dp[i];
        pref[i] %= mod;
    }
    cout << dp[n] << '\n';
}