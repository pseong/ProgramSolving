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

int dp[110][1010][555];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    fill(&dp[0][0][0], &dp[109][1009][555], -inf);
    dp[0][0][0] = 0;
    for (int x=1; x<=n; x++) {
        int c, r, p;
        cin >> c >> r >> p;
        for (int i=0; i<=1001; i++) {
            for (int j=0; j<=500; j++) {
                dp[x][i][j] = max(dp[x][i][j], dp[x-1][i][j]);
                if (i + c <= 1000) dp[x][i+c][j+p] = max(dp[x][i+c][j+p], dp[x-1][i][j] + r);
                else dp[x][1001][j+p] = max(dp[x][1001][j+p], dp[x-1][i][j] + r);
            }
        }
    }
    for (int j=1; j<=500; j++) {
        for (int i=m; i<=1001; i++) {
            if (dp[n][i][j] >= k) {
                cout << j << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}