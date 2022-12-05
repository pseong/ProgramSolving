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

int dp[1010][1010], dpl[1010], dpr[1010];
const int mod = 10301;
int n, a, b;

int f(int n, int x) {
    if (n == x) return dp[n][x] = 1;
    if (dp[n][x] != -1) return dp[n][x];
    int res = 0;
    for (int i=x; i*2<=n; i++) {
        res += f(n-i, i);
        res %= mod;
    }
    return dp[n][x] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(dp, -1, sizeof dp);
    cin >> n >> a >> b;
    for (int i=1; i<=1000; i++) {
        for (int j=1; j<=i; j++) {
            f(i, j);
        }
    }
    for (int i=a; i<=n-b+1; i++) {
        dpl[i] = dp[i][a];
    }
    for (int i=b; i<=n-a+1; i++) {
        dpr[i] = dp[i][b];
    }
    for (int i=1; i<=n/2; i++) {
        swap(dpr[i], dpr[n-i+1]);
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            ans += dpl[i] * dpr[j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
}