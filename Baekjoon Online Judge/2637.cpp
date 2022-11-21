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

vector<pi> adj[110];
int cnt[110], in[110], out[110], chk[110];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        in[b]++;
        out[a]++;
    }
    queue<int> q;
    q.push(n);
    cnt[n] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto [y, w] : adj[x]) {
            cnt[y] += cnt[x] * w;
            if (--in[y] == 0) q.push(y);
        }
    }
    vector<pi> ans;
    for (int i=1; i<=n; i++) {
        if (out[i] == 0) {
            ans.push_back({i, cnt[i]});
        }
    }
    for (auto [x, cnt] : ans) {
        cout << x << ' ' << cnt << '\n';
    }
}