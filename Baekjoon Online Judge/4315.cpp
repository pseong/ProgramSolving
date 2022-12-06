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

int cnt[10101], dp[10101];
vector<int> adj[10101];
ll ans;

int go(int x, int p) {
    dp[x] = 1;
    ll res = 0;
    for (int y : adj[x]) {
        if (y == p) continue;
        res += go(y, x);
        dp[x] += dp[y];
    }
    ans += abs(dp[x] - (res + cnt[x]));
    return res + cnt[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        ans = 0;
        for (int i=1; i<=n; i++) {
            cnt[i] = 0;
            dp[i] = 0;
            adj[i].clear();
        }
        for (int k=1; k<=n; k++) {
            int v, x, c;
            cin >> v >> x >> c;
            cnt[v] = x;
            for (int i=0; i<c; i++) {
                int a;
                cin >> a;
                adj[v].push_back(a);
                adj[a].push_back(v);
            }
        }
        go(1, 0);
        cout << ans << '\n';
    }
}