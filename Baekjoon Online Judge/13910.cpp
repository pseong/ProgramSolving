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

ll dp[10101];
const ll inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<m; i++) {
        cin >> v[i];
    }
    fill(dp, dp + 10101, inf);
    dp[0] = 0;
    for (int i=0; i<m; i++) {
        int x = v[i];
        for (int k=0; k<=n; k++) {
            if (k - x >= 0) dp[k] = min(dp[k], dp[k-x] + 1);
        }
        for (int j=i+1; j<m; j++) {
            int x = v[i] + v[j];
            for (int k=0; k<=n; k++) {
                if (k - x >= 0) dp[k] = min(dp[k], dp[k-x] + 1);
            }
        }
    }
    if (dp[n] == inf) cout << -1 << '\n';
    else cout << dp[n] << '\n';
}