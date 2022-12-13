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

char mp[10][10];
int dp[10][10], dp2[10][10];
const int inf = 1e5;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            dp[i][j] = -inf;
            dp2[i][j] = inf;
        }
    }
    dp[1][1] = mp[1][1] - '0';
    dp2[1][1] = mp[1][1] - '0';
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (mp[i-1][j] == '+') {
                if (i > 2) dp[i][j] = max(dp[i][j], dp[i-2][j] + (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (mp[i][j] - '0'));

                if (i > 2) dp2[i][j] = min(dp2[i][j], dp2[i-2][j] + (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp2[i][j] = min(dp2[i][j], dp2[i-1][j-1] + (mp[i][j] - '0'));
            }
            else if (mp[i-1][j] == '-') {
                if (i > 2) dp[i][j] = max(dp[i][j], dp[i-2][j] - (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] - (mp[i][j] - '0'));
                
                if (i > 2) dp2[i][j] = min(dp2[i][j], dp2[i-2][j] - (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp2[i][j] = min(dp2[i][j], dp2[i-1][j-1] - (mp[i][j] - '0'));
            }
            else if (mp[i-1][j] == '*') {
                if (i > 2) dp[i][j] = max(dp[i][j], dp[i-2][j] * (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] * (mp[i][j] - '0'));

                if (i > 2) dp2[i][j] = min(dp2[i][j], dp2[i-2][j] * (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp2[i][j] = min(dp2[i][j], dp2[i-1][j-1] * (mp[i][j] - '0'));
            }

            if (mp[i][j-1] == '+') {
                if (j > 2) dp[i][j] = max(dp[i][j], dp[i][j-2] + (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + (mp[i][j] - '0'));

                if (j > 2) dp2[i][j] = min(dp2[i][j], dp2[i][j-2] + (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp2[i][j] = min(dp2[i][j], dp2[i-1][j-1] + (mp[i][j] - '0'));
            }
            else if (mp[i][j-1] == '-') {
                if (j > 2) dp[i][j] = max(dp[i][j], dp[i][j-2] - (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] - (mp[i][j] - '0'));

                if (j > 2) dp2[i][j] = min(dp2[i][j], dp2[i][j-2] - (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp2[i][j] = min(dp2[i][j], dp2[i-1][j-1] - (mp[i][j] - '0'));
            }
            else if (mp[i][j-1] == '*') {
                if (j > 2) dp[i][j] = max(dp[i][j], dp[i][j-2] * (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] * (mp[i][j] - '0'));

                if (j > 2) dp2[i][j] = min(dp2[i][j], dp2[i][j-2] * (mp[i][j] - '0'));
                if (i > 1 && j > 1) dp2[i][j] = min(dp2[i][j], dp2[i-1][j-1] * (mp[i][j] - '0'));
            }
        }
    }
    cout << dp[n][n] << ' ' << dp2[n][n] << '\n';
}