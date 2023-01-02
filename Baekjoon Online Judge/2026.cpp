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

vector<int> adj[1000];
vector<int> now;
int k, n, f, ok, fd[1000][1000];

void go(int x) {
    if (ok) return;
    if (now.size() == k) {
        ok = true;
        for (int a : now) {
            cout << a << '\n';
        }
        return;
    }
    for (int y : adj[x]) {
        if (y <= x) continue;
        bool ok = true;
        for (int z : now) {
            if (fd[z][y] == 0) ok = false;
        }
        if (!ok) continue;
        now.push_back(y);
        go(y);
        now.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> k >> n >> f;
    for (int i=0; i<f; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) continue;
        if (a > b) swap(a, b);
        fd[a][b] = 1;
        fd[b][a] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    for (int i=1; i<=n; i++) {
        now.push_back(i);
        go(i);
        now.pop_back();
        if (ok) return 0;
    }
    cout << -1 << '\n';
}