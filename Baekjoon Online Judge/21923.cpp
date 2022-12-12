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

ll udp[1010][1010], ddp[1010][1010], v[1010][1010];
const ll inf = 1e18;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i=0; i<1010; i++) {
        for (int j=0; j<1010; j++) {
            udp[i][j] = -inf;
            ddp[i][j] = -inf;
        }
    }
    udp[n][0] = 0;
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=m; j++) {
            udp[i][j] = max(udp[i+1][j], udp[i][j-1]) + v[i][j];
        }
    }
    ddp[n][m+1] = 0;
    for (int i=n; i>=1; i--) {
        for (int j=m; j>=1; j--) {
            ddp[i][j] = max(ddp[i+1][j], ddp[i][j+1]) + v[i][j];
        }
    }
    ll ans = -inf;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            ans = max(ans, udp[i][j] + ddp[i][j]);
        }
    }
    cout << ans << '\n';
}