#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

ll f(vector<ll>& v, int val) {
    ll amt = abs(v[0]-val);
    for (int i=1; i<v.size(); i++) {
        if (abs(v[i]-val) < amt) {
            amt = abs(v[i]-val);
        }
    }
    return amt;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> an(n, 0);
        vector<ll> bn(n, 0);
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        for (int i=0; i<n; i++) {
            cin >> bn[i];
        }

        ll f_l = f(bn, an[0]);
        ll f_r = f(bn, an[n-1]);
        ll s_l = f(an, bn[0]);
        ll s_r = f(an, bn[n-1]);

        ll ans = f_l + f_r + s_l + s_r;
        ans = min(ans, abs(an[0]-bn[0]) + abs(an[n-1]-bn[n-1]));
        ans = min(ans, abs(an[0]-bn[n-1]) + abs(an[n-1]-bn[0]));
        ans = min(ans, abs(an[0]-bn[0]) + f_r + s_r);
        ans = min(ans, abs(an[n-1]-bn[n-1]) + f_l + s_l);
        ans = min(ans, abs(an[n-1]-bn[0]) + f_l + s_r);
        ans = min(ans, abs(an[0]-bn[n-1]) + f_r + s_l);

        cout << ans << '\n';
    }
}