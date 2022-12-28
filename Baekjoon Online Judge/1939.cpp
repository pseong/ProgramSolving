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
int from, to;
int n, m;

bool f(int m) {
    vector<int> chk(n + 1);
    chk[from] = 1;
    queue<int> q;
    q.push(from);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto [y, c] : adj[x]) {
            if (chk[y] || c < m) continue;
            chk[y] = 1;
            q.push(y);
        }
    }
    return chk[to];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> from >> to;

    int lo = 1;
    int hi = 1e9;
    int ans = 0;
    while (lo <= hi) {
        int m = lo + (hi - lo) / 2;
        if (f(m)) {
            ans = m;
            lo = m + 1;
        }
        else {
            hi = m - 1;
        }
    }
    cout << ans << '\n';
}