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

struct Point {
    ll x, y;
};

Point v[555];
ll dp[555][555];
ll inf = 1e18;

ll dist(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(&dp[0][0], &dp[554][555], inf);

    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    dp[1][0] = 0;
    for (int i=2; i<=n; i++) {
        for (int j=0; j<=min(m, i-2); j++) {
            for (int k=0; k<=j; k++) {
                dp[i][j] = min(dp[i][j], dp[i-k-1][j-k] + dist(v[i-k-1], v[i]));
            }
        }
    }
    cout << dp[n][m] << '\n';
}