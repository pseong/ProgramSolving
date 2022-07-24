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

struct Query {
    int w, s, e;
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Query> v(n);
    int cnt = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i].w;
        if (v[i].w == 1) {
            cin >> v[i].s;
            cnt++;
        }
        else {
            cin >> v[i].s >> v[i].e;
        }
    }

    vector<int> adj(505050), chk(505050);
    for (int i=0; i<505050; i++) {
        adj[i] = i;
    }

    vector<int> ans(cnt+1);
    int c = cnt;
    for (int i=n-1; i>=0; i--) {
        if (v[i].w == 1) {
            ans[c] = adj[v[i].s];
            c--;
        }
        else {
            adj[v[i].s] = adj[v[i].e];
        }
    }
    for (int i=1; i<=cnt; i++) {
        cout << ans[i] << ' ';
    }
}