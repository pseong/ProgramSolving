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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, y;
    cin >> x >> y;
    const ll inf = 1e18;
    vector<vector<ll>> dp(550, vector<ll>(550, inf));
    for (int i=1; i<=500; i++) {
        dp[1][i] = 1;
        dp[i][1] = i;
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for (int n=2; n<=500; n++) {
        for (int k=2; k<=500; k++) {
            for (int m=1; m<=n; m++) {
                dp[n][k] = min(dp[n][k], max(dp[m-1][k], dp[n-m][k-1]) + 1);
            }
        }
    }
    cout << dp[x][y];
}