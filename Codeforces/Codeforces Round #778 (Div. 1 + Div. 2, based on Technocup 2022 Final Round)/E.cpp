#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int n, an[101010], ans;
const int S = 350;
int bucket[70707070];
unordered_map<int, int> dp[101010];

void solve() {
    int BIAS = 35353535;
    for (int d=0; d<S; d++) {
        for (int i=0; i<n; i++) {
            ans = max(ans, ++bucket[an[i]-i*d+BIAS]);
        }
        for (int i=0; i<n; i++) {
            bucket[an[i]-i*d+BIAS] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=max(0, i-S-1); j<i; j++) {
            int d = (an[i]-an[j]) / (i-j);
            int r = (an[i]-an[j]) % (i-j);
            if (r==0 && d >= S) {
                dp[i][d] = max(dp[i][d], dp[j][d]+1);
                ans = max(ans, dp[i][d]+1);
            }
        }
    }

    for (int i=0; i<n; i++) {
        dp[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> an[i];
    }
    solve();
    reverse(an, an+n);
    solve();
    cout << n-ans;
}