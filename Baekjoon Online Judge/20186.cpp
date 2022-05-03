#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll minus = (k-1)*k/2;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());
    ll ans = -minus;
    for (int i=0; i<k; i++) {
        ans += v[i];
    }
    cout << ans;
}