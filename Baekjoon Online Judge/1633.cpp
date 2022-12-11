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

ll dp[1010][16][16];
const ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> v{ {0, 0} };
    int n, m;
    while (cin >> n >> m) {
        v.push_back({n, m});
    }
    n = v.size() - 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=15; j++) {
            for (int k=0; k<=15; k++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k]);
                if (j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + v[i][0]);
                if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + v[i][1]);
            }
        }
    }
    cout << dp[n][15][15] << '\n';
}