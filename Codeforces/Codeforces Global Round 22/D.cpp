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

vector<int> adj[101010];

void solve(int CASE) {
    int n;
    cin >> n;
    for (int i=0; i<=n+1; i++) adj[i].clear();
    vector<int> v(n + 1);
    int k = 0;
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        if (i < v[i]) k = i;
    }
    for (int i=1; i<=n; i++) {
        adj[v[i]].push_back(i);
    }
    int r = adj[0].size() ? 0 : n + 1;
    vector<int> q = { r };
    for (int i=0; i<q.size(); i++) {
        int x = q[i];
        sort(all(adj[x]), [&](int a, int b) {
            return adj[a].size() < adj[b].size();
        });
        for (int y : adj[x]) q.push_back(y);
    }
    cout << k << '\n';
    for (int i=1; i<n+1; i++) {
        cout << q[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}