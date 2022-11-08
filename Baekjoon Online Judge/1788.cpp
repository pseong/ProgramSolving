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

ll dp[2020202];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[1000001] = 1;
    for (int i=1000002; i<=2000000; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1000000000;
    }
    for (int i=999999; i>=0; i--) {
        dp[i] = dp[i+2] - dp[i+1];
        dp[i] %= 1000000000;
    }
    int n;
    cin >> n;
    n += 1000000;
    if (dp[n] < 0) cout << -1 << '\n';
    else if (dp[n] > 0) cout << 1 << '\n';
    else cout << 0 << '\n';
    cout << abs(dp[n]) << '\n';
}