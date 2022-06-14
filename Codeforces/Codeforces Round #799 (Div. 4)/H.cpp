#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

map<ll, vector<ll>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T; cin >> T;
    while (T--) {
        mp.clear();
        ll n; cin >> n;
        for (ll i=0; i<n; i++) {
            ll a; cin >> a;
            mp[a].push_back(i);
        }
        vector<tuple<ll, ll, ll, ll>> candidate;
        for (auto at : mp) {
            vector<ll>& v = at.second;
            ll m = v.size();
            vector<pi> dp(m);
            dp[0].first = v[0];
            dp[0].second = 1;
            ll mx = dp[0].second;
            ll mx_l = dp[0].first;
            ll mx_r = dp[0].first;
            for (ll i=1; i<m; i++) {
                if (dp[i-1].second - v[i] + v[i-1] + 1 > 0) {
                    dp[i].first = dp[i-1].first;
                    dp[i].second = dp[i-1].second - v[i] + v[i-1] + 2;
                }
                else {
                    dp[i].first = v[i];
                    dp[i].second = 1;
                }
                if (mx < dp[i].second) {
                    mx = dp[i].second;
                    mx_l = dp[i].first;
                    mx_r = v[i];
                }
            }
            candidate.push_back({mx, mx_l, mx_r, at.first});
        }
        sort(candidate.rbegin(), candidate.rend());
        ll mx, l, r, a;
        tie(mx, l, r, a) = candidate.front();
        cout << a << ' ' << l+1 << ' ' << r+1 << '\n';
    }
}