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
void no() { cout << "Bob" << '\n'; }
void yes() { cout << "Alice" << '\n'; }

int dp[110][110][2];

void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    vector<int> cnt(2);
    for (int i=0; i<n; i++) {
        cnt[v[i]&1]++;
    }
    if (dp[cnt[0]][cnt[1]][0]) yes();
    else no();
}

int DP(int x, int y, int k) {
    if (x < 0 || y < 0) return 1;
    else return dp[x][y][k];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=0; i<=100; i++) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 0;
    }
    for (int j=4; j<=100; j+=4) {
        dp[0][j-1][0] = 1;
        dp[0][j][0] = 1;
        dp[0][j-3][1] = 1;
        dp[0][j-2][1] = 1; 
    }

    for (int i=1; i<=100; i++) {
        for (int j=1; j<=100; j++) {
            if (DP(i-2, j, 0) && DP(i-1, j-1, 0)) dp[i][j][0] = 1;
            if (DP(i, j-2, 1) && DP(i-1, j-1, 1)) dp[i][j][0] = 1;

            if (DP(i-2, j, 1) && DP(i-1, j-1, 1)) dp[i][j][1] = 1;
            if (DP(i, j-2, 0) && DP(i-1, j-1, 0)) dp[i][j][1] = 1;
        }
    }

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}