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

vector<int> adj[101010];
int n;

vector<int> bfs(int x) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[x] = 0;
    q.push(x);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (dist[y] != -1) continue;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
    return dist;
}

int far(int x) {
    vector<int> dist = bfs(x);
    int r = max_element(dist.begin() + 1, dist.end()) - dist.begin();
    return r;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int x = far(1);
    int y = far(x);
    vector<int> a = bfs(x);
    vector<int> b = bfs(y);
    vector<int> d(n + 1);
    for (int i=1; i<=n; i++) {
        d[i] = max(a[i], b[i]);
    }
    sort(d.begin(), d.end());
    int cur = 1;
    for (int i=1; i<=n; i++) {
        while (cur <= n && d[cur] < i) cur++;
        if (cur == n + 1) cout << n << ' ';
        else cout << cur << ' ';
    }
}