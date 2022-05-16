#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int chk[101010];
vector<int> adj[101010];
int ord = 1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> q;
    chk[r] = ord;
    ord++;
    q.push_back(r);
    for (int i=0; i<q.size(); i++) {
        for (int y : adj[q[i]]) {
            if (chk[y]) continue;
            chk[y] = ord;
            ord++;
            q.push_back(y);
        }
    }
    for (int i=1; i<=n; i++) {
        cout << chk[i] << '\n';
    }
}