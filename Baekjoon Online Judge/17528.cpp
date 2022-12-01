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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    const int inf = 1e9;
    int sum = 0;
    vector<int> dp(n*250 + 1, inf);
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        auto tmp = dp;
        int a, b;
        cin >> a >> b;
        sum += a;
        for (int j=0; j<=n*250; j++) {
            if (j-a >= 0) tmp[j] = min(tmp[j], dp[j-a] + b);
        }
        dp = tmp;
    }
    int ans = inf;
    for (int i=0; i<=sum; i++) {
        ans = min(ans, max(sum - i, dp[i]));
    }
    cout << ans << '\n';
}