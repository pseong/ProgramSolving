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
    int n;
    cin >> n;
    vector<ll> v(n*2);
    for (int i=0; i<n*2; i++) {
        cin >> v[i];
    }
    ll ans = 0;
    for (int i=0; i<n*2; i++) {
        ans += abs(v[i]);
    }
    if (n == 1) {
        ans = min(ans, abs(v[0] - v[1]));
    }
    if (n == 2) {
        ans = min(ans, abs(2 - v[0]) + abs(2 - v[1]) + abs(2 - v[2]) + abs(2 - v[3]));
    }
    if (n%2 == 0) {
        ll x = 0;
        sort(v.begin(), v.end());
        for (int i=0; i<n*2-1; i++) {
            x += abs(v[i] + 1);
        }
        x += abs(v[n*2-1] - n);
        ans = min(ans, x);
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