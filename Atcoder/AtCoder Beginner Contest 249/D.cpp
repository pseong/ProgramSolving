#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int a, n;
    cin >> n;
    vector<int> cnt(200001);
    int mx = 0;
    for (int i=0; i<n; i++) {
        cin >> a;
        mx = max(mx, a);
        cnt[a]++;
    }
    ll ans = 0;
    for (int p=1; p<=mx; p++) {
        for (int q=1; p*q<=mx; q++) {
            ans += (ll)cnt[q] * cnt[p] * cnt[p*q];
        }
    }
    cout << ans;
}