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

vector<int> adj[220];
int c[220], d[220];

bool dfs(int x) {
    c[x] = 1;
    for (int y : adj[x]) {
        if (c[y]) continue;
        c[y] = 1;
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, s, v;
    while (cin >> n >> m >> s >> v) {
        for (int i=0; i<220; i++) {
            adj[i].clear();
            c[i] = 0;
            d[i] = 0;
        }
        vector<pair<double, double>> w(n + 1);
        for (int i=1; i<=n; i++) {
            cin >> w[i].first >> w[i].second;
        }
        vector<pair<double, double>> t(m + 1);
        for (int i=1; i<=m; i++) {
            cin >> t[i].first >> t[i].second;
        }
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                double dst = (w[i].first - t[j].first) * (w[i].first - t[j].first) + (w[i].second - t[j].second) * (w[i].second - t[j].second);
                if (sqrt(dst) <= (double)s * (double)v) {
                    adj[i].push_back(j + 100);
                }
            }
        }

        int cnt = 0;
        for (int i=1; i<=n; i++) {
            memset(c, 0, sizeof c);
            if (dfs(i)) cnt++;
        }
        cout << n - cnt << '\n';
    }
}