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

int n, v[550][550], dp[550][550];
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

int go(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    for (int d=0; d<4; d++) {
        int a = x + dx[d];
        int b = y + dy[d];
        if (a < 1 || a > n || b < 1 || b > n) continue;
        if (v[x][y] >= v[a][b]) continue;
        dp[x][y] = max(dp[x][y], go(a, b));
    }
    return dp[x][y] += 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            ans = max(ans, go(i, j));
        }
    }
    cout << ans << '\n';
}