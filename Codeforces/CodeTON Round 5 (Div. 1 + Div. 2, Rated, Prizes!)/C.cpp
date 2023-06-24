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

const int inf = 1e9;

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n + 1), dp(n + 1), mx(n + 1, -inf);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) {
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], mx[v[i]] + i + 1);
        mx[v[i]] = max(mx[v[i]], dp[i-1] - i);
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}