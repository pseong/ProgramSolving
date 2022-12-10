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

int dp[5050][2];
const int inf = 1e6;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(4));
    for (int i=0; i<5050; i++) {
        for (int j=0; j<2; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i=1; i<n; i++) {
        cin >> v[i][1] >> v[i][2];
    }
    int k;
    cin >> k;
    dp[1][0] = 0;
    for (int i=1; i<n; i++) {
        if (i + 1 <= n) dp[i+1][0] = min(dp[i+1][0], dp[i][0] + v[i][1]);
        if (i + 2 <= n) dp[i+2][0] = min(dp[i+2][0], dp[i][0] + v[i][2]);
        if (i + 1 <= n) dp[i+1][1] = min(dp[i+1][1], dp[i][1] + v[i][1]);
        if (i + 2 <= n) dp[i+2][1] = min(dp[i+2][1], dp[i][1] + v[i][2]);
        if (i + 3 <= n) dp[i+3][1] = min(dp[i+3][1], dp[i][0] + k);
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
}