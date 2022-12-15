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

ll v[10], dp[11][11][11][11][11][6][6];

ll f(int a, int b, int c, int d, int e, int pref, int now) {
    if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0) return 1;
    ll& x = dp[a][b][c][d][e][pref][now];
    if (x != -1) return x;
    x = 0;
    if (a && pref != 1 && now != 1) x += f(a - 1, b, c, d, e, now, 1);
    if (b && pref != 2 && now != 2) x += f(a, b - 1, c, d, e, now, 2);
    if (c && pref != 3 && now != 3) x += f(a, b, c - 1, d, e, now, 3);
    if (d && pref != 4 && now != 4) x += f(a, b, c, d - 1, e, now, 4);
    if (e && pref != 5 && now != 5) x += f(a, b, c, d, e - 1, now, 5);
    return x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(&dp[0][0][0][0][0][0][0], &dp[10][10][10][10][10][5][6], -1);

    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    cout << f(v[1], v[2], v[3], v[4], v[5], 0, 0) << '\n';
}