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

int v[5050], dp[5050][5050];
const int inf = 1e9;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<5050; i++) {
        for (int j=0; j<5050; j++) {
            dp[i][j] = inf;
        }
    }
    for (int i=1; i<=n; i++) {
        dp[i][i] = 0;
    }
    for (int len=1; len<n; len++) {
        for (int l=1; l<=n-len+1; l++) {
            int r = l + len;
            if (v[l] == v[r]) {
                if (len == 1) dp[l][r] = 0;
                else dp[l][r] = dp[l+1][r-1];
            }
            else dp[l][r] = min(dp[l][r-1], dp[l+1][r]) + 1;
        }
    }
    cout << dp[1][n] << '\n';
}