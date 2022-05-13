#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
int dp[15][15][1<<14];

int go(int i, int j, int status) {
    if (j >= m) i++, j %= m;
    if (dp[i][j][status] != -1) return dp[i][j][status];
    if (i == n && j == 0) {
        return dp[i][j][status] = 1;
    }
    if (status & 1) {
        return dp[i][j][status] = go(i, j+1, status>>1);
    }
    int cnt = 0;
    if (i < n-1) {
        cnt += go(i, j+1, (status>>1) | (1<<m-1));
        cnt %= 9901;
    }
    if (j < m-1 && !(status & 2)) {
        cnt += go(i, j+2, (status>>2));
        cnt %= 9901;
    }
    return dp[i][j][status] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    cin >> n >> m;

    if (n*m % 2) cout << 0;
    else cout << go(0, 0, 0);
}