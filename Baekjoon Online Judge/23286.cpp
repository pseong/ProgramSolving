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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;
    const int inf = 10000000;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 10000000));
    for (int i=1; i<=n; i++) {
        v[i][i] = 0;
    }
    for (int i=0; i<m; i++) {
        int s, e, h;
        cin >> s >> e >> h;
        v[s][e] = min(v[s][e], h);
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                v[i][j] = min(v[i][j], max(v[i][k], v[k][j]));
            }
        }
    }
    for (int i=0; i<t; i++) {
        int s, e;
        cin >> s >> e;
        if (v[s][e] == inf) cout << -1 << '\n';
        else cout << v[s][e] << '\n';
    }
}