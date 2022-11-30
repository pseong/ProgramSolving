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

int v[2525][2525];

int p[2525];
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
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
            if (i < j) lst.push_back({v[i][j], i, j});
        }
    }
    for (int i=1; i<=n; i++) {
        p[i] = i;
    }
    sort(lst.begin(), lst.end());
    vector<pi> ans;
    for (auto [w, i, j] : lst) {
        if (!same(i, j)) {
            merge(i, j);
            ans.push_back({i, j});
        }
    }
    for (auto [i, j] : ans) {
        cout << i << ' ' <<  j << '\n';
    }
}