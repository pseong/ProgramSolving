#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

void solve(int CASE) {
    ll n, k;
    cin >> n >> k;
    vector<ll> f(n), d(n);
    for (int i=0; i<n; i++) cin >> f[i];
    for (int i=0; i<n; i++) cin >> d[i];
    ll ans = n;
    for (int i=0; i<n; i++) {
        ll fd = f[i]*d[i];
        ll cnt = 0;
        vector<vector<pll>> event(k*2 + 1);
        for (int j=0; j<n; j++) {
            if (fd >= f[j] && fd/f[j]*f[j] >= fd-k && fd/f[j]*f[j] <= fd+k) event[fd/f[j]*f[j] - (fd-k)].push_back({j, 0});
            if ((fd/f[j]+1)*f[j] >= fd-k && (fd/f[j]+1)*f[j] <= fd+k) event[(fd/f[j]+1)*f[j] - (fd-k)].push_back({j, 0});
            if (f[j]*d[j] >= fd-k && f[j]*d[j] <= fd+k) event[f[j]*d[j] - (fd-k)].push_back({j, 1});
        }
        vector<pll> v(n, {0LL, 0LL});
        ll acnt = 0;
        ll ncnt = 0;
        for (int i=0; i<k*2+1; i++) {
            for (auto [idx, val] : event[i]) {
                if (v[idx].first == 0 && v[idx].second == 0) acnt++;
                if (val == 0) {
                    v[idx].first++;
                }
                else if (val == 1) {
                    ncnt++;
                    v[idx].second++;
                }
            }
            if (acnt == n) ans = min(ans, n-ncnt);
            if (i-k >= 0)
            for (auto [idx, val] : event[i-k]) {
                if (val == 0) {
                    v[idx].first--;
                }
                else if (val == 1) {
                    ncnt--;
                    v[idx].second--;
                }
                if (v[idx].first == 0 && v[idx].second == 0) acnt--;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}