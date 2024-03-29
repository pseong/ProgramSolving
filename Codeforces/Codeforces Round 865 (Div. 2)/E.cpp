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

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> depth(n + 1), adj(n + 1);
    vector<int> c(n + 1, 1e9);
    int s = n * (n + 1)/2;
    vector<int> v(s + 1);
    int to = 1;
    int go = n;
    for (int i=1; i<=s; i++) {
        v[i] = go;
        go--;
        if (go < to) {
            to++;
            go = n;
        }
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    queue<int> q;
    c[1] = 1;
    q.push(1);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (c[y] != 1e9) continue;
            c[y] = c[x] + 1;
            q.push(y);
        }
    }
    for (int i=1; i<=n; i++) {
        if (c[i] == 1e9) {
            cout << "INFINITE\n";
            return;
        }
        depth[c[i]].push_back(i);
    }
    cout << "FINITE\n";
    vector<int> ans;
    for (int i=1; i<=s; i++) { 
        for (int x : depth[v[i]]) {
            ans.push_back(x);
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
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


// 사이클이 생겼을 때 1로 갈 수 없다면 INFINITE 있다면 FINITE