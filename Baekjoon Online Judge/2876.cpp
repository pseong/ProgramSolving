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

ll v[101010][2], dp[101010][6];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    vector<int> ans(2);
    for (int i=1; i<=n; i++) {
        if (v[i-1][0] == v[i][0] || v[i-1][1] == v[i][0]) dp[i][v[i][0]] = dp[i-1][v[i][0]] + 1;
        else dp[i][v[i][0]] = 1;
        if (v[i-1][0] == v[i][1] || v[i-1][1] == v[i][1]) dp[i][v[i][1]] = dp[i-1][v[i][1]] + 1;
        else dp[i][v[i][1]] = 1;
        if (ans[1] < dp[i][v[i][0]] || ans[1] == dp[i][v[i][0]] && ans[0] > v[i][0]) {
            ans[0] = v[i][0];
            ans[1] = dp[i][v[i][0]];
        }
        if (ans[1] < dp[i][v[i][1]] || ans[1] == dp[i][v[i][1]] && ans[0] > v[i][1]) {
            ans[0] = v[i][1];
            ans[1] = dp[i][v[i][1]];
        }
    }
    cout << ans[1] << ' ' << ans[0] << '\n';
}