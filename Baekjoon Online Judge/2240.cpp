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

int dp[3][1001][31];
int v[3][1001];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, w;
    cin >> t >> w;
    for (int i=1; i<=t; i++) {
        int a;
        cin >> a;
        v[a][i] = 1;
    }

    for (int i=1; i<=t; i++) {
        dp[1][i][0] += dp[1][i-1][0] + v[1][i];
    }

    for (int i=1; i<=t; i++) {
        for (int d=1; d<=w; d++) {
            dp[1][i][d] = max(dp[1][i-1][d], dp[2][i-1][d-1]) + v[1][i];
            dp[2][i][d] = max(dp[2][i-1][d], dp[1][i-1][d-1]) + v[2][i];
        }
    }
    cout << max(dp[1][t][w], dp[2][t][w]) << '\n';
}