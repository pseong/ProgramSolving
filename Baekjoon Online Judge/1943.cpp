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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<pi> v(n + 1);
    int sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].first * v[i].second;
    }
    if (sum % 2 == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=sum; j++) {
            if (dp[i-1][j]) {
                for (int k=0; k<=v[i].second; k++) {
                    dp[i][j + v[i].first * k] = 1;
                }
            }
        }
    }
    cout << dp[n][sum/2] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 3;\
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}