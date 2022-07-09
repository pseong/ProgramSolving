#include <bits/stdc++.h>
#define int long long
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

vector<int> adj[100];
int c[100], d[100];

bool dfs(int x) {
    for (int y : adj[x]) {
        if (c[y]) continue;
        c[y] = true;
        if (d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}


struct shark {
    int a, b, c;
};

void solve() {
    int n; cin >> n;
    vector<shark> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) continue;
            if (v[i].a == v[j].a && v[i].b == v[j].b && v[i].c == v[j].c) {
                if (i > j) continue;
                adj[i].push_back(j);
            }
            else if (v[i].a >= v[j].a && v[i].b >= v[j].b && v[i].c >= v[j].c) {
                adj[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        fill(c, c + 100, 0);
        if (dfs(i)) ans++;
        fill(c, c + 100, 0);
        if (dfs(i)) ans++;
    }
    cout << n - ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}