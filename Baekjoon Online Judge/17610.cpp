#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

bool dp[14][3000000];
int k, s, v[14];

void go(int i, int w) {
    if (i > k || dp[i][w]) return;
    dp[i][w] = true;
    go(i+1, w+v[i]);
    go(i+1, abs(w-v[i]));
    go(i+1, w);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> v[i];
        s += v[i];
    }
    go(0, 0);

    int ans = 0;
    for (int i=1; i<=s; i++) {
        if (dp[k][i] == false) ans++;
    }
    cout << ans;
}