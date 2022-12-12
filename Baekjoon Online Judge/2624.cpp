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

int dp[110][10101];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, k;
    cin >> t >> k;
    dp[0][0] = 1;
    for (int i=1; i<=k; i++) {
        int x, c;
        cin >> x >> c;
        for (int j=0; j<=t; j++) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j=0; j<=t; j++) {
            for (int y=1; y<=c; y++) {
                int sum = x * y;
                if (j + sum <= t) {
                    dp[i][j + sum] += dp[i-1][j];
                }
            }
        }
    }
    cout << dp[k][t] << '\n';
}