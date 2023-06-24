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
 
vector<pll> adj[1010];
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pi> p;
    for (int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> chk(n);
    queue<int> q;
    q.push(0);
    chk[0] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto [y, c] : adj[x]) {
            if (chk[y]) continue;
            chk[y] = 1;
            q.push(y);
        }
    }
    if (!chk[n-1]) {
        cout << "inf\n";
        return 0;
    }
    vector<pair<string, ll>> log;
    string s = string(n, '0');
    ll ans = 0;
    s[0] = '1';
    while (s[n-1] == '0') {
        ll add = 1e18;
        vector<pair<int, tuple_element<1, pair<ll, ll>>::type*>> can;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                for (auto& [j, c]: adj[i]) {
                    if (s[j] == '1') continue;
                    add = min(add, c);
                    can.push_back({j, &c});
                }
            }
        }
        ans += add;
        log.push_back({s, add});
        for (auto [x, y] : can) {
            *y -= add;
            if (*y == 0) s[x] = '1';
        }
    }
 
    cout << ans << ' ' << log.size() << '\n';
    for (auto [x, y] : log) {
        cout << x << ' ' << y << '\n';
    }
}