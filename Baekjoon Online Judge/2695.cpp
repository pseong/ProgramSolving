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

vector<vector<ll>> dp;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    const ll inf = 1e18;
    dp.assign(1010, vector<ll>(55, inf));
    for (int i=1; i<=1000; i++) {
        dp[1][min(i, 50)] = 1;
        dp[i][1] = i;
        dp[i][0] = 0;
        dp[0][min(i, 50)] = 0;
    }
    for (int n=2; n<=1000; n++) {
        for (int k=2; k<=50; k++) {
            for (int m=1; m<=n; m++) {
                dp[n][k] = min(dp[n][k], max(dp[m-1][k], dp[n-m][k-1]) + 1);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int y, x;
        cin >> y >> x;
        cout << dp[x][y] << '\n';
    }
}