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

ll dp[110][110];
set<tuple<int, int, int, int>> st;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    n++, m++;
    for (int i=0; i<k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        st.insert({a+1, b+1, c+1, d+1});
        st.insert({c+1, d+1, a+1, b+1});
    }

    dp[1][1] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!st.count({i, j, i-1, j})) dp[i][j] += dp[i-1][j];
            if (!st.count({i, j, i, j-1})) dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[n][m] << '\n';
}