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

ll mn[550][550];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i=0; i<550; i++) {
        for (int j=0; j<550; j++) {
            mn[i][j] = 1e18;
        }
    }
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 2));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> sum(n + 1, vector<ll>(n + 2));
    for (int i=1; i<=n; i++) {
        for (int j=n; j>=1; j--) {
            sum[i][j] = sum[i][j+1] + v[i][j];
        }
    }
    for (int j=1; j<=n; j++) {
        ll s = sum[1][j];
        for (int i=1; i<=n; i++) {
            s = min(s, sum[i][j]);
            mn[i][j] = s;
        }
    }
    while (q--) {
        int x, y, l;
        cin >> x >> y >> l;
        ll s = 0;
        ll ans = sum[x][y];
        for (int j=y; j<=n; j++) {
            if (x - l >= 1) ans = min(ans, mn[x-l][j] + s);
            s += v[x][j];
        }
        cout << ans << '\n';
    }
}