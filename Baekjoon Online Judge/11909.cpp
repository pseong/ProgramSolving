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

ll v[2500][2500], dp[2500][2500];
ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(&v[0][0], &v[2499][2500], -inf);
    fill(&dp[0][0], &dp[2499][2500], inf);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    dp[1][1] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = min({dp[i][j], dp[i-1][j] + max(0LL, v[i][j] + 1 - v[i-1][j]), dp[i][j-1] + max(0LL, v[i][j] + 1 - v[i][j-1])});
        }
    }
    cout << dp[n][n] << '\n';
}