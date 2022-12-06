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

int n;
vector<int> adj[303030];
i128 dp[303030][5], dp2[303030][3];

void go(int x, int p) {
    for (int y : adj[x]) {
        if (y == p) continue;
        go(y, x);
        for (int i=2; i<=4; i++) {
            dp[x][i] += dp[y][i-1];
        }
    }
    i128 cnt = adj[x].size();
    if (p != 0) cnt--;
    if (cnt >= 2) dp2[x][1] = cnt * (cnt - 1) / 2;
    if (cnt >= 3) dp2[x][0] = cnt * (cnt - 1) * (cnt - 2) / 6;
    for (int y : adj[x]) {
        if (y == p) continue;
        dp2[x][0] += dp2[y][1];
        dp2[x][2] += dp[y][2] * (cnt - 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        dp[i][1] = 1;
    }
    go(1, 0);
    i128 d = 0, g = 0;
    for (int i=1; i<=n; i++) {
        d += dp[i][4] + dp2[i][2];
        g += dp2[i][0];
    }
    if (d > g*3) cout << "D\n";
    else if (d < g*3) cout << "G\n";
    else cout << "DUDUDUNGA\n";
}