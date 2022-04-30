#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

const int mod = 1000000007;
vector<int> pals;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=1; i<=40000; i++) {
        int j = 0;
        int a = i;
        while (a > 0) {
            j = j*10 + a%10;
            a /= 10;
        }
        if (i == j) pals.push_back(i);
    }
    
    vector<int> dp(40001, 0);
    dp[0] = 1;
    for (int p : pals) {
        for (int i=p; i<=40000; i++) {
            dp[i] = (dp[i] + dp[i-p]) % mod;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}