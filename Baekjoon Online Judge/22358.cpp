#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector<pi> down[101010];
vector<int> up[101010];
ll dp[101010][11];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;
    for (int i=0; i<m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        down[a].push_back({b, t});
        up[b].push_back(a);
    }
    memset(dp, -1, sizeof dp);
    dp[s][0] = 0;
    for (int x=s; x<=n; x++) {
        if (dp[x][0] == -1) continue;
        for (auto at : down[x]) {
            int y, tm;
            tie(y, tm) = at;
            dp[y][0] = max(dp[y][0], dp[x][0] + tm);
        }
    }
    for (int z=1; z<=k; z++) {
        for (int x=1; x<=n; x++) {
            for (int y : up[x]) {
                dp[y][z] = max(dp[y][z], dp[x][z-1]);
            }
        }
        for (int x=1; x<=n; x++) {
            if (dp[x][z] == -1) continue;
            for (auto at : down[x]) {
                int y, tm;
                tie(y, tm) = at;
                dp[y][z] = max(dp[y][z], dp[x][z] + tm);
            }
        }
    }
    cout << dp[t][k];
}