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

int ans, n, m, chk[22][22], v[22];

void go(int x) {
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (v[i]) cnt++;
    }
    ans = max(ans, min(n, cnt + 1));
    if (x >= n) return;
    go(x + 1);
    for (int y=x+1; y<n; y++) {
        if (chk[x][y] && !v[x] && !v[y]) {
            v[x] = 1;
            v[y] = 1;
            go(x + 1);
            v[x] = 0;
            v[y] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        chk[a][b] = 1;
        chk[b][a] = 1;
    }
    go(0);
    cout << ans << '\n';
}