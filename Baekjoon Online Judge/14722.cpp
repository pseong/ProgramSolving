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

int v[1010][1010], dp[1010][1010][3];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=0; k<3; k++) {
                dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
            }
            int x = v[i][j];
            dp[i][j][x] = max({dp[i][j][x], dp[i-1][j][(x+2)%3] + 1, dp[i][j-1][(x+2)%3] + 1});
            if (x != 0 && dp[i][j][x] == 1) dp[i][j][x] = 0;
        }
    }
    cout << max({dp[n][n][0], dp[n][n][1], dp[n][n][2]}) << '\n';
}