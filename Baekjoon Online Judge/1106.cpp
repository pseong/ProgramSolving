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

int dp[2020];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int c, n;
    cin >> c >> n;
    fill(dp, dp+2020, inf);
    dp[0] = 0;
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i=0; i<n; i++) {
        int w = v[i].first;
        int x = v[i].second;
        for (int j=0; j<2020; j++) {
            if (j + x < 2020) {
                dp[j + x] = min(dp[j + x], dp[j] + w);
            }   
        }
    }
    int ans = inf;
    for (int i=c; i<2020; i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
}