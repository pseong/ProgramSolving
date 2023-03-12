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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n + 1), cold(k + 1), hot(k + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=k; i++) cin >> cold[i];
    for (int i=1; i<=k; i++) cin >> hot[i];
    vector<ll> dp(k + 1, 1e18);
    dp[0] = 0;
    vector<ll> d(k + 1, 1e18);
    d[0] = 0;
    ll add = 0;
    ll mn = 0;
    for (int i=1; i<=n; i++) {
        if (v[i] == v[i-1]) {
            ll dvi = d[v[i]] + add;
            add += hot[v[i]];
            mn += hot[v[i]];
            if (d[v[i]] + add > mn - hot[v[i]] + cold[v[i]]) {
                d[v[i]] = mn - hot[v[i]] + cold[v[i]] - add;
            }
            if (d[v[i]] + add > dvi + hot[v[i]]) {
                d[v[i]] = dvi + hot[v[i]] - add;
            }
            if (mn > d[v[i]] + add) mn = d[v[i]] + add;
        }
        else {
            ll dvi = d[v[i]] + add;
            add += cold[v[i]];
            mn += cold[v[i]];
            if (d[v[i-1]] + add > mn) {
                d[v[i-1]] = mn - add;
            }
            if (d[v[i-1]] + add > dvi + hot[v[i]]) {
                d[v[i-1]] = dvi + hot[v[i]] - add;
            }
            if (mn > d[v[i-1]] + add) mn = d[v[i-1]] + add;
        }
    }
    cout << mn << '\n';
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