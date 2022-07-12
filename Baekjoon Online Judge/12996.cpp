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

int n, a, b, c;
ll dp[60][60][60][60];
const ll mod = 1000000007;

ll f(int n, int a, int b, int c) {
    if (n == 0 && a == 0 && b == 0 && c == 0) return 1;
    if (n == 0 || a < 0 || b < 0 || c < 0) return 0;
    if (dp[n][a][b][c] != -1) return dp[n][a][b][c];
    ll ans = 0;
    ans += f(n-1, a-1, b, c);
    ans += f(n-1, a, b-1, c);
    ans += f(n-1, a, b, c-1);
    ans += f(n-1, a-1, b-1, c);
    ans += f(n-1, a-1, b, c-1);
    ans += f(n-1, a, b-1, c-1);
    ans += f(n-1, a-1, b-1, c-1);
    return dp[n][a][b][c] = ans % mod;
}

void solve() {
    cin >> n >> a >> b >> c;
    for (int i=0; i<60; i++) {
        for (int j=0; j<60; j++) {
            for (int k=0; k<60; k++) {
                for (int l=0; l<60; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    cout << f(n, a, b, c);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}