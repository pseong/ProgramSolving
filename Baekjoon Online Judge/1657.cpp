#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, m, ans;
string s[15];
ll dp[15][15][1<<15];
ll table[6][6] {
    {10, 8, 7, 5, 0, 1},
    {8, 6, 4, 3, 0, 1},
    {7, 4, 3, 2, 0, 1},
    {5, 3, 2, 2, 0, 1},
    {0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0},
};

ll go(ll i, ll j, ll status, ll sum) {
    if (j >= m) i++, j %= m;
    ll ret = 0;
    if (dp[i][j][status] != -1) ret = dp[i][j][status];
    else if (i == n && j == 0) ret = dp[i][j][status] = 0;
    else if (status & 1) ret = dp[i][j][status] = go(i, j+1, status>>1, sum);
    else {
        ret = max(ret, go(i, j+1, status>>1, sum));
        if (i < n-1) {
            ret = max(ret, table[s[i][j]-'A'][s[i+1][j]-'A'] + go(i, j+1, (status>>1) | (1<<m-1), sum + table[s[i][j]-'A'][s[i+1][j]-'A']));
        }
        if (j < m-1 && !(status & 2)) {
            ret = max(ret, table[s[i][j]-'A'][s[i][j+1]-'A'] + go(i, j+2, (status>>2), sum + table[s[i][j]-'A'][s[i][j+1]-'A']));
        }
    }
    ans = max(ans, sum + ret);
    return dp[i][j][status] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> s[i];

    go(0, 0, 0, 0);
    cout << ans;
}