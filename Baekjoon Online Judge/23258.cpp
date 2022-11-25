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

ll w[310][310][310];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    const ll inf = 1000000000000;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> w[0][i][j];
            if (w[0][i][j] == 0 && i != j) w[0][i][j] = inf;
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                w[k][i][j] = w[k-1][i][j];
            }
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                w[k][i][j] = min(w[k][i][j], w[k][i][k] + w[k][k][j]);
            }
        }
    }
    for (int i=0; i<q; i++) {
        int c, s, e;
        cin >> c >> s >> e;
        if (w[c-1][s][e] == inf) cout << -1 << '\n';
        else cout << w[c-1][s][e] << '\n';
    }
}