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
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    vector<pi> a(n);
    for (int i=0; i<n; i++) cin >> a[i].first, a[i].second = i;
    for (int i=0; i<m; i++) cin >> b[i];
    sort(all(a), [](pi x, pi y) -> bool {
        return x.first > y.first;
    });
    vector<vector<int>> go(m, vector<int>(n));
    for (int i=0; i<m; i++) {
        int r = 0;
        for (int l=0; l<n; l++) {
            while (r < n && b[i] > 1LL * a[r].first * (r - l + 1)) r++;
            go[i][l] = r;
        }
    }
    vector<int> dp(1 << m, 1e9);
    vector<int> hist(1 << m);
    dp[0] = -1;
    for (int mask=1; mask<(1<<m); mask++) {
        for (int i=0; i<m; i++) {
            if (mask & (1 << i)) {
                int x = dp[mask & ~(1 << i)] + 1;
                if (x < n) x = go[i][x];
                if (dp[mask] > x) {
                    dp[mask] = x;
                    hist[mask] = i;
                }
            }
        }
    }
    int mask = (1 << m) - 1;
    if (dp[mask] >= n) no();
    else {
        yes();
        vector<vector<int>> ans(m);
        while (mask) {
            int nmask = mask & ~(1 << hist[mask]);
            for (int i=dp[nmask]+1; i<=dp[mask]; i++) {
                ans[hist[mask]].push_back(i);
            }
            mask = nmask;
        }
        for (int i=0; i<m; i++) {
            cout << ans[i].size() << ' ';
            for (int x : ans[i]) cout << a[x].second + 1 << ' ';
            cout << '\n';
        }
    }
}