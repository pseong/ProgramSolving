#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    int start = -1000000000;
    int end = -1000000000;
    for (int i=0; i<v.size(); i++) {
        if (v[i].first > end) {
            ans += end-start;
            start = v[i].first;
            end = v[i].second;
        }
        else {
            end = max(end, v[i].second);
        }
    }
    ans += end-start;
    cout << ans;
}