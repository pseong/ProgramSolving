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

int v[20][20], chk[20][20], n, m, k, ans;

void go(int x, int y, int idx, int sum) {
    if (y >= m) {
        y = 0;
        x++;
    }
    if (idx == k) {
        ans = max(ans, sum);
        return;
    }
    for (int i=x; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i == x && j < y) continue;
            if (i > 0 && chk[i-1][j]) continue;
            if (j > 0 && chk[i][j-1]) continue;
            chk[i][j] = 1;
            go(i, j + 1, idx+1, sum + v[i][j]);
            chk[i][j] = 0;
        }
    }
}

void solve(int CASE) {
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> v[i][j];
        }
    }
    ans = -1000000000;
    go(0, 0, 0, 0);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}