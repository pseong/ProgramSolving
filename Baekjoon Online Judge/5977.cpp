#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll sum[101010], an[101010], dp[101010][2];

deque<pll> q;
int n, k;
ll add(ll idx, ll x) {
    while (q.size() && q.back().second <= x) {
        q.pop_back();
    }
    q.push_back({idx, x});
    if (q.front().first == idx-k) q.pop_front();
    return q.front().second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        sum[i] = sum[i-1] + an[i];
    }
    for (int i=1; i<=n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = add(i, dp[i-1][0] - sum[i-1]) + sum[i];
    }
    cout << max(dp[n][0], dp[n][1]);
}