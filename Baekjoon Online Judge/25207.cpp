#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int cnt, n, an[505050], in[505050], out[505050], ett[505050], chi[505050];
int in2[505050], out2[505050], ett2[505050], chi2[505050];
vector<int> adj[505050];

void dfs(int x) {
    in[x] = ++cnt;
    ett[in[x]] = an[x];
    for (int y : adj[x]) {
        dfs(y);
    }
    out[x] = cnt;
    chi[in[x]] = out[x] - in[x] + 1;
}

void dfs2(int x) {
    in2[x] = ++cnt;
    ett2[in2[x]] = an[x];
    for (int y : adj[x]) {
        dfs2(y);
    }
    out2[x] = cnt;
    chi2[in2[x]] = out2[x] - in2[x] + 1;
}

bool comp(int l, int r, int l2, int r2) {
    int go = l;
    int go2 = l2;
    while (l <= r) {
        if (ett[go] != ett2[go2] || chi[go] != chi2[go2]) return false;
        l++;
        l2++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
    }
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(1);
    for (int i=1; i<=n; i++) {
        sort(adj[i].rbegin(), adj[i].rend());
    }
    cnt = 0;
    dfs2(1);

    vector<int> ans;
    for (int i=1; i<=n; i++) {
        if (in[i] == out[i]) {
            ans.push_back(i);
            continue;
        }
        if (comp(in[i]+1, out[i], in2[i]+1, out2[i])) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}