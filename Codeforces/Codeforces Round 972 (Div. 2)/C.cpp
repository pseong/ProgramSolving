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
    int n, m;
    cin >> n >> m;
    vector<string> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(5, -1e9));
    string t = "narek";
    dp[0][4] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<5; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            ll score = dp[i][j];
            int p = (j + 1) % 5;
            for (int k=0; k<m; k++) {
                if (v[i + 1][k] == t[p]) {
                    p++;
                    if (p == 5) {
                        score += 5;
                        p = 0;
                    }
                }
                else if (t.find(v[i + 1][k]) != string::npos) {
                    score--;
                }
            }
            p = (p + 4) % 5;
            dp[i + 1][p] = max(dp[i + 1][p], score);
        }
    }
    ll ans = 0;
    for (int j=0; j<5; j++) {
        ans = max(ans, dp[n][j] - (j + 1) % 5);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("C:/dnrseong/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}