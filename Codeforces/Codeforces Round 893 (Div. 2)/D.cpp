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
    ll n, k;
    string s;
    cin >> n >> k >> s;
    s.insert(s.begin(), ' ');
    vector<vector<ll>> pref(n + 2, vector<ll>(n + 2));
    vector<vector<ll>> suf(n + 2, vector<ll>(n + 2));
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            if (s[i] == '0') pref[i][j] = pref[i-1][j] + 1;
            else if (j > 0) pref[i][j] = pref[i-1][j-1] + 1;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            pref[i][j] = max(pref[i][j], pref[i-1][j]);
            if (j-1 >= 0) pref[i][j] = max(pref[i][j], pref[i][j-1]);
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=0; j<=n; j++) {
            if (s[i] == '0') suf[i][j] = suf[i+1][j] + 1;
            else if (j > 0) suf[i][j] = suf[i+1][j-1] + 1;
        }
    }
    for (int i=n; i>=1; i--) {
        for (int j=0; j<=n; j++) {
            suf[i][j] = max(suf[i][j], suf[i+1][j]);
            if (j-1 >= 0) suf[i][j] = max(suf[i][j], suf[i][j-1]);
        }
    }
    vector<ll> dp(n + 2, -1);
    dp[0] = pref[n][k];
    for (int i=1; i<=n; i++) {
        int c0 = 0;
        for (int j=i; j<=n; j++) {
            if (s[j] == '0') c0++;
            if (k-c0 >= 0) dp[j-i+1] = max({dp[j-i+1], pref[i-1][k-c0], suf[j+1][k-c0]});
        }
    }
    for (int a=1; a<=n; a++) {
        ll ans = 0;
        for (int i=0; i<=n; i++) {
            if (dp[i] != -1) ans = max(ans, a*dp[i] + i);
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}