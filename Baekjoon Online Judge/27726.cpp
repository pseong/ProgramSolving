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
        if (x > y) swap(x, y);
        return parent[y] = x;
    }
    bool same(int x, int y) {
        return leader(x) == leader(y);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Dsu dsu1, dsu2, dsu3;
    dsu1.init(n);
    dsu2.init(n);
    dsu3.init(n);
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    for (int i=0; i<t1; i++) {
        int a, b;
        cin >> a >> b;
        dsu1.merge(a, b);
    }
    for (int i=0; i<t2; i++) {
        int a, b;
        cin >> a >> b;
        dsu2.merge(a, b);
    }
    for (int i=0; i<t3; i++) {
        int a, b;
        cin >> a >> b;
        dsu3.merge(a, b);
    }
    map<int, vector<int>> g;
    for (int i=1; i<=n; i++) {
        g[dsu1.leader(i)].push_back(i);
    }

    vector<vector<int>> v;
    for (auto at : g) {
        map<int, vector<int>> ng;
        for (int x : at.second) {
            ng[dsu2.leader(x)].push_back(x);
        }
        for (auto& [x, y] : ng) {
            v.push_back(y);
        }
    }

    vector<vector<int>> v2;
    for (auto& vec : v) {
        map<int, vector<int>> ng;
        for (int x : vec) {
            ng[dsu3.leader(x)].push_back(x);
        }
        for (auto& [x, y] : ng) {
            v2.push_back(y);
        }
    }
    vector<vector<int>> ans;
    for (auto& v : v2) {
        if (v.size() >= 2) {
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto& v : ans) {
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}