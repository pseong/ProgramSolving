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

bool dp[55][2600][2600];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int sum = 0;
    dp[0][0][0] = 1;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        sum += a;
        for (int j=0; j<=2500; j++) {
            for (int k=0; k<=2500; k++) {
                dp[i][j][k] |= dp[i-1][j][k];
                if (j-a >= 0) dp[i][j][k] |= dp[i-1][j-a][k];
                if (k-a >= 0) dp[i][j][k] |= dp[i-1][j][k-a];
            }
        }
    }
    int ans = 0;
    for (int i=0; i<=2500; i++) {
        for (int j=0; j<=2500; j++) {
            int k = sum - i - j;
            if (dp[n][i][j]) {
                ans = max(ans, min({i, j, k}));
            }
        }
    }
    cout << ans << '\n';
}