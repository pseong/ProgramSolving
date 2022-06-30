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
        if (x > y) swap(x, y);
        return parent[y] = x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
};

void solve() {
    int n, d;
    cin >> n >> d;
    vector<pi> v(d);
    for (int i=0; i<d; i++) {
        cin >> v[i].first >> v[i].second;
    }
    for (int i=0; i<d; i++) {
        Dsu dsu(n);
        int have = 0;
        for (int j=0; j<=i; j++) {
            if (dsu.same(v[j].first, v[j].second)) {
                have++;
            }
            else dsu.merge(v[j].first, v[j].second);
        }
        vector<int> cnt(n+1);
        for (int i=1; i<=n; i++) {
            cnt[dsu.leader(i)]++;
        }
        vector<int> g;
        for (int i=1; i<=n; i++) {
            if (cnt[i] != 0) g.push_back(cnt[i]);
        }
        int sz = g.size();
        srtrev(g);
        int ans = g.front()-1;
        for (int i=1; i<=min(sz, have); i++) {
            ans += g[i];
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}