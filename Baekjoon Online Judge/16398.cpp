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

int w[1010], cost[1010][1010], parent[1010];

int find(int a) {
    if (parent[a] == parent[parent[a]]) return parent[a];
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) swap(a, b);
    parent[b] = a;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    

    int n;
    cin >> n;
    vector<ti> v;
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> cost[i][j];
            if (i != j) {
                v.push_back({cost[i][j], i, j});
            }
        }
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for (int i=0; i<(int)v.size(); i++) {
        auto [c, a, b] = v[i];
        if (same(a, b)) continue;
        ans += c;
        merge(a, b);
    }
    cout << ans << '\n';
}