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

char mp[10][10];
int dp[10][10], dp2[10][10];
const int inf = 1e5;
int n;

// 0 : +, 1 : -, 2 : *
void go(int x, int y, int now, int op) {
    if (mp[x][y] >= '0' && mp[x][y] <= '5') {
        int z = mp[x][y] - '0';
        if (op == 0) z = now + z;
        else if (op == 1) z = now - z;
        else z = now * z;
        dp[x][y] = max(dp[x][y], z);
        dp2[x][y] = min(dp2[x][y], z);
        if (x + 1 <= n) go(x + 1, y, z, 0);
        if (y + 1 <= n) go(x, y + 1, z, 0);
    }
    else {
        int p = 0;
        if (mp[x][y] == '+') p = 0;
        else if (mp[x][y] == '-') p = 1;
        else p = 2;
        if (x + 1 <= n) go(x + 1, y, now, p);
        if (y + 1 <= n) go(x, y + 1, now, p);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> mp[i][j];
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            dp[i][j] = -inf;
        }
    }
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            dp2[i][j] = inf;
        }
    }
    go(1, 1, 0, 0);
    cout << dp[n][n] << ' ' << dp2[n][n] << '\n';
}