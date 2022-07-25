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

vector<pi> adj[101010];

void solve(int CASE) {
    int n;
    cin >> n;
    for (int i=0; i<=n; i++) {
        adj[i].clear();
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for (int i=1; i<=n; i++) {
        if (adj[i].size() >= 3) {
            cout << -1 << '\n';
            return;
        }
    }
    int x = 1;
    for (int i=1; i<=n; i++) {
        if (adj[i].size() == 1) {
            x = i;
            break;
        }
    }
    vector<int> ans(n-1);
    int y = adj[x][0].first;
    ans[adj[x][0].second] = 2;
    int cur = 2;
    while (adj[y].size() == 2) {
        int t = x == adj[y][0].first;
        cur = 5 - cur;
        ans[adj[y][t].second] = cur;
        x = adj[y][t].first;
        swap(x, y);
    }
    for (int i=0; i<n-1; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}