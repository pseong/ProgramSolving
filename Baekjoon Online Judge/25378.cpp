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
    
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> chk(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        int now = v[i];
        int f = 1;
        for (int j=i+1; j<=n; j++) {
            if (now == v[j]) chk[i][j] = f;
            else {
                chk[i][j] = 0;
                if (now > v[j]) f = 0;
            }
            now = abs(now - v[j]);
        }
    }

    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + 1;
        for (int j=1; j<i; j++) {
            if (chk[j][i] == 0) continue;
            dp[i] = min(dp[i], dp[j-1] + i - j);
        }
    }
    cout << dp[n] << '\n';
}