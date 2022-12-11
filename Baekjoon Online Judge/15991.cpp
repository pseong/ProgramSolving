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

ll dp[101010];
const ll mod = 1000000009;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    for (int i=1; i<=100000; i++) {
        if (i >= 2) dp[i] += dp[i-2];
        if (i >= 4) dp[i] += dp[i-4];
        if (i >= 6) dp[i] += dp[i-6];
        dp[i] %= mod;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}