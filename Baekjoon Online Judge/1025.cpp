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

int v[15][15];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=m; j++) {
            v[i][j] = s[j-1] - '0';
        }
    }
    int ans = -1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int a=-10; a<=10; a++) {
                for (int b=-10; b<=10; b++) {
                    if (a == 0 && b == 0) continue;
                    int x = i;
                    int y = j;
                    int now = 0;
                    while (x >= 1 && x <= n && y >= 1 && y <= m) {
                        now *= 10;
                        now += v[x][y];
                        x += a;
                        y += b;
                        if (sqrt(now) == (int)sqrt(now)) ans = max(ans, now);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}