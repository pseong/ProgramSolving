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

struct Dsu {
    vector<int> parent;
    Dsu() {};
    Dsu(int n) {
        init(n);
    }
    void init(int n) {
        parent.resize(n+1);
        for (int i=1; i<=n; i++) {
            parent[i] = i;
        }
    }
    int leader(int i) {
        if (parent[i] == i) return i;
        return parent[i] = leader(parent[i]);
    }
    int merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x < y) swap(x, y);
        return parent[y] = x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
};
 
void solve() {
    int n; cin >> n;
    Dsu dsu(n);
    vector<int> v(n+1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    vector<ti> t;
    for (int i=1; i<=n; i++) {
        if (v[i] == 0) {
            t.push_back({n, i+1, i});
        }
        else {
            t.push_back({i/v[i], i/(v[i]+1)+1, i});
        }
    }
    srt(t);
    vector<int> ans(n+1);
    for (auto [e, s, i] : t) {
        ans[i] = dsu.leader(s);
        if (ans[i] < n) dsu.merge(ans[i], ans[i] + 1);
    }
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin >> T;
    while (T--) {
        solve();
    }
}