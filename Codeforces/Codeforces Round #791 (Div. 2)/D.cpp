#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
ll k;
int U[202020], V[202020], an[202020];
vector<int> adj[202020];
int indeg[202020], cnt[202020];

bool cal(int mid) {
    for (int i=1; i<=n; i++) {
        adj[i].clear();
        indeg[i] = 0;
        cnt[i] = 0;
    }
    for (int i=0; i<m; i++) {
        if (an[U[i]] <= mid && an[V[i]] <= mid) {
            adj[U[i]].push_back(V[i]);
            indeg[V[i]]++;
        }
    }
    queue<int> q;
    for (int i=1; i<=n; i++) {
        if (an[i] > mid) continue;
        if (indeg[i] == 0) q.push(i);
    }
    vector<int> v;
    while (q.size()) {
        int x = q.front(); q.pop();
        v.push_back(x);
        for (int y : adj[x]) {
            if (--indeg[y] == 0) q.push(y);
        }
    }
    for (int i=1; i<=n; i++) {
        if (an[i] > mid) continue;
        if (indeg[i] > 0) return true;
    }
    reverse(v.begin(), v.end());
    int mx = 0;
    for (int i=0; i<(int)v.size(); i++) {
        int t = 1;
        for (int y : adj[v[i]]) t = max(t, cnt[y] + 1);
        cnt[v[i]] = t;
        mx = max(mx, t);
    }
    if (mx >= k) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for (int i=0; i<m; i++) {
        cin >> U[i] >> V[i];
    }
    
    int lo = 1;
    int hi = 1e9;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (cal(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans;
}