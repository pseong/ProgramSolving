#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll, ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<pii> v;
    for (ll i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) v.push_back({b, a});
    }

    sort(v.begin(), v.end());
    ll start = 0;
    ll end = 0;
    ll ans = 0;
    for (ll i=0; i<v.size(); i++) {
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
    cout << m+ans*2;
}