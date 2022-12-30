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

int n, m, s[20][4], chk[20], e;
vector<int> v[20];
vector<pi> adj[20];

void go(int idx) {
    if (e) return;
    if (idx == n) {
        e = 1;
        cout << "YES\n";
        for (int i=0; i<n; i++) {
            cout << chk[i] + 1 << ' ';
        }
        cout << '\n';
    }
    for (int x : v[idx]) {
        if (chk[x] != -1) continue;
        bool ok = true;
        for (auto [y, c] : adj[x]) {
            if (chk[y] != -1 && s[idx][c] != s[chk[y]][c]) ok = false;
        }
        if (!ok) continue;
        chk[x] = idx;
        go(idx + 1);
        chk[x] = -1;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(chk, -1, sizeof chk);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            cin >> s[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[i].push_back(a);
        if (a != b) v[i].push_back(b);
    }
    for (int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        t--;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    go(0);
    if (!e) cout << "NO\n";
}