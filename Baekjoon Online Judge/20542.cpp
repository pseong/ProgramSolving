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

vector<vector<int>> dp;
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    dp.resize(n + 1, vector<int>(m + 1, inf));
    string a, b;
    cin >> a >> b;
    a.insert(a.begin(), '0');
    b.insert(b.begin(), '0');
    for (int j=0; j<=m; j++) {
        dp[0][j] = j;
    }
    for (int i=0; i<=n; i++) {
        dp[i][0] = i;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((a[i] == 'v' && b[j] == 'w') || (a[i] == 'i' && (b[j] == 'j' || b[j] == 'l')) || a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j-1] + 1, dp[i-1][j] + 1, dp[i][j-1] + 1});
        }
    }
    cout << dp[n][m] << '\n';
}