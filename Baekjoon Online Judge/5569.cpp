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

const int mod = 100000;
int dp[110][110][4];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int w, h;
    cin >> w >> h;
    dp[1][3][3] = 1;
    dp[2][2][1] = 1;
    dp[2][2][2] = 1;
    dp[3][1][0] = 1;
    for (int i=1; i<=w; i++) {
        for (int j=1; j<=h; j++) {
            if (i + j <= 4) continue;
            dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] += dp[i-1][j][3];
            dp[i][j][2] += dp[i][j-1][0];
            dp[i][j][3] += dp[i][j-1][2] + dp[i][j-1][3];
            for (int k=0; k<4; k++) {
                dp[i][j][k] %= mod;
            }
        }
    }
    cout << (dp[w][h][0] + dp[w][h][1] + dp[w][h][2] + dp[w][h][3]) % mod<< '\n';
}