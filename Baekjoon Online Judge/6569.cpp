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

int h, w;
ll dp[11][11][1<<11];

ll dfs(int x, int y, int now) {
    if (y >= w) y %= w, x++;
    if (x == h) return 1;
    if (dp[x][y][now] != -1) return dp[x][y][now];
    ll ans = 0;
    if (now & 1) ans += dfs(x, y + 1, now >> 1);
    else {
        if (!(now & 2) && y + 1 < w) ans += dfs(x, y + 2, now >> 2);
        if (x + 1 < h) ans += dfs(x, y + 1, (now>>1) | (1<<w-1));
    }
    return dp[x][y][now] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        cin >> h >> w;
        if (h == 0 && w == 0) break;
        memset(dp, -1, sizeof dp);
        cout << dfs(0, 0, 0) << '\n';
    }
}