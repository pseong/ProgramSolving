#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll mod = 1e9 + 7;
int n, pi, pj, px, py;
vector<vector<int>> dp;

bool valid(int p, int v) {
    if (p == pi && v != px) return false;
    if (p == pj && v != py) return false;
    return true;
}

int f(int l, int r) {
    if (l == r) {
        if (valid(l, n)) {
            if (l == 1 || l == n) return 0;
            else return 1;
        }
        else return 0;
    }
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;
    int val = n - (r - l);
    if (valid(r, val)) dp[l][r] += f(l, r-1);
    dp[l][r] %= mod;
    if (valid(l, val)) dp[l][r] += f(l+1, r);
    dp[l][r] %= mod;
    return dp[l][r];
}

void solve(int CASE) {
    cin >> n >> pi >> pj >> px >> py;
    dp.assign(n + 1, vector<int>(n + 1, -1));
    cout << f(1, n) << '\n';
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