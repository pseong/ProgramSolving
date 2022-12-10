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

int dp[50][50];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    dp[1][1] = 1;
    for (int i=2; i<=30; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    int r, c, w;
    cin >> r >> c >> w;
    int ans = 0;
    for (int i=r; i<r+w; i++) {
        for (int j=c; j<=c+i-r; j++) {
            ans += dp[i][j];
        }
    }
    cout << ans;
}