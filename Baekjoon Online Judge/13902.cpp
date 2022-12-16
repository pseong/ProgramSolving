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

int dp[10001];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    fill(dp, dp + 10001, inf);

    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (int i=0; i<m; i++) {
        cin >> v[i];
    }
    vector<int> vv;
    for (int i=0; i<m; i++) {
        vv.push_back(v[i]);
        for (int j=i+1; j<m; j++) {
            if (v[i] + v[j] <= 10000) vv.push_back(v[i] + v[j]);
        }
    }
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    dp[0] = 0;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<(int)vv.size(); j++) {
            if (i + vv[j] <= n) dp[i + vv[j]] = min(dp[i + vv[j]], dp[i] + 1);
        }
    }
    if (dp[n] == inf) cout << -1 << '\n';
    else cout << dp[n] << '\n';
}