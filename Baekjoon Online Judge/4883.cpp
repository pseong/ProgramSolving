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

    int T = 0;
    while (++T) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<vector<int>> v(n + 1, vector<int>(30));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=3; j++) {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(4, 2000000000));
        dp[1][2] = v[1][2];
        dp[1][3] = v[1][2] + v[1][3];
        for (int i=2; i<=n; i++) {
            dp[i][1] = min({dp[i][1], min({dp[i-1][1], dp[i-1][2]}) + v[i][1]});
            dp[i][2] = min({dp[i][2], min({dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i][1]}) + v[i][2]});
            dp[i][3] = min({dp[i][3], min({dp[i-1][2], dp[i-1][3], dp[i][2]}) + v[i][3]});
        }
        cout << T << ". " << dp[n][2] << '\n';
    }
}