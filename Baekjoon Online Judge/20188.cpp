#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

vector<int> adj[303030];
ll n, ans;

ll dfs(int x, int p) {
    ll sum = 0;
    for (int y : adj[x]) {
        if (y == p) continue;
        ll g = dfs(y, x);
        ans += sum*g*2;
        ans += g*(g-1)/2;
        sum += g;
    }
    ans += sum*(n-sum);
    return sum + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    cout << ans;
}