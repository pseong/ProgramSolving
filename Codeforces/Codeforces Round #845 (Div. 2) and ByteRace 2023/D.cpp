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

const ll mod = 1e9+7;

ll cnt, dep[202020];
vector<int> adj[202020];

void go(int x, int p) {
    dep[x] = 1;
    for (int y : adj[x]) {
        if (y == p) continue;
        go(y, x);
        dep[x] = max(dep[x], dep[y] + 1);
    }
    cnt += dep[x];
    cnt %= mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<=n; i++) {
            adj[i].clear();
            cnt = 0;
        }
        for (int i=0; i<n-1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        go(1, 0);
        ll x = 1;
        for (int i=0; i<n-1; i++) {
            x *= 2;
            x %= mod;
        }
        cout << x * cnt % mod << '\n';
    }
}