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


vector<ll> v;

bool comp(int l, int r) {
    return v[l] < v[r];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    v.resize(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    const ll inf = 1000000000;
    vector<vector<ll>> w(n + 1, vector<ll>(n + 1, inf));
    vector<vector<ll>> p(n + 1, vector<ll>(n + 1, inf));
    for (int i=1; i<=n; i++) {
        w[i][i] = 0;
        p[i][i] = v[i];
    }
    for (int i=0; i<m; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        w[a][b] = min(w[a][b], d);
        w[b][a] = min(w[b][a], d);
        p[a][b] = max({v[a], v[b]});
        p[b][a] = max({v[a], v[b]});
    }
    vector<int> lst(n);
    for (int i=0; i<n; i++) {
        lst[i] = i + 1;
    }
    sort(lst.begin(), lst.end(), comp);
    for (int k : lst) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (w[i][k] != inf && w[k][j] != inf && w[i][j] + p[i][j] > w[i][k] + w[k][j] + max({v[k], v[i], v[j]})) {
                    w[i][j] = w[i][k] + w[k][j];
                    p[i][j] = max({v[k], v[i], v[j]});
                }
            }
        }
    }
    for (int i=0; i<q; i++) {
        int s, e;
        cin >> s >> e;
        if (w[s][e] == inf) cout << -1 << '\n';
        else cout << w[s][e] + p[s][e] << '\n';
    }
}