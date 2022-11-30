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

int v[1050][1050];
vector<int> adj[1050];

int ans[1050][1050];
int c[1050][1050];

int p[1050];
int find(int x) {
    if (p[x] == p[p[x]]) return p[x];
    else return p[x] = find(p[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x > y) swap(x, y);
    p[y] = x;
}
bool same(int x, int y) {
    return find(x) == find(y);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    int n;
    cin >> n;
    vector<ti> lst;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            cin >> v[i][j];
            lst.push_back({v[i][j], i, j});
        }
    }
    for (int i=1; i<=n; i++) {
        p[i] = i;
    }
    sort(lst.begin(), lst.end());
    for (auto [w, i, j] : lst) {
        if (!same(i, j)) {
            merge(i, j);
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << adj[i].size() << ' ';
        sort(adj[i].begin(), adj[i].end());
        for (int j : adj[i]) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}