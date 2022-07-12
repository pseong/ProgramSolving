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

vector<int> adj[202020], w[202020];
int col[202020];

bool bipart(int i) {
    queue<pi> q;
    q.push({i, 0});
    while (q.size()) {
        auto [x, c] = q.front();
        q.pop();
        if (col[x] == -1) {
            col[x] = c;
            for (int y : adj[x]) {
                if (col[y] == -1) q.push({y, c^1});
                else if (col[y] != c^1) return false;
            }
        }
        else if (col[x] != c) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        adj[i].clear();
        w[i].clear();
        col[i] = -1;
    }
    vector<pi> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i=1; i<=n; i++) {
        w[v[i].first].push_back(i);
        w[v[i].second].push_back(i);
    }
    for (int i=1; i<=n; i++) {
        if (w[i].size() >= 3) {
            no();
            return;
        }
    }
    for (int i=1; i<=n; i++) {
        if (w[i].size() == 2) {
            adj[w[i][0]].push_back(w[i][1]);
            adj[w[i][1]].push_back(w[i][0]);
        }
    }
    for (int i=1; i<=n; i++) {
        if (col[i] == -1) {
            if (bipart(i) == false) {
                no();
                return;
            }
        }
    }
    yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}