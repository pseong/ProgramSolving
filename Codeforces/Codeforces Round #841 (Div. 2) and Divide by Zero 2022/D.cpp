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

bool cal(int mid, vector<vector<int>>& v, int n, int m) {
    int res = 0;
    vector<vector<int>> chk(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (v[i][j] >= mid) chk[i][j] = 1;
            if (chk[i][j]) chk[i][j] = min({chk[i-1][j], chk[i-1][j-1], chk[i][j-1]}) + 1;
            res = max(res, chk[i][j]);
        }
    }
    return res >= mid;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(m + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> v[i][j];
        }
    }
    int lo = 1;
    int hi = min(n, m);
    int ans = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (cal(mid, v, n, m)) {
            lo = mid + 1;
            ans = mid;
        }
        else hi = mid - 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}