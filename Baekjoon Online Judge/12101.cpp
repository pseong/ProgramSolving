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

vector<vector<int>> dp[20];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[0].push_back({});
    for (int i=1; i<=11; i++) {
        for (auto at : dp[i-1]) {
            at.push_back(1);
            dp[i].push_back(at);
        }
        if (i >= 2) for (auto at : dp[i-2]) {
            at.push_back(2);
            dp[i].push_back(at);
        }
        if (i >= 3) for (auto at : dp[i-3]) {
            at.push_back(3);
            dp[i].push_back(at);
        }
    }
    int n, k;
    cin >> n >> k;
    sort(dp[n].begin(), dp[n].end());
    if (dp[n].size() < k) {
        cout << -1 << '\n';
        return 0;
    }
    int sz = dp[n][k-1].size();
    for (int i=0; i<sz; i++) {
        cout << dp[n][k-1][i];
        if (i != sz-1) cout << '+';
    }
}