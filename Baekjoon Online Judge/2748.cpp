#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll dp[95];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[1] = 1;
    for (int i=2; i<=90; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    int n; cin >> n;
    cout << dp[n];
}