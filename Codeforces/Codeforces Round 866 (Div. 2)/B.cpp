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
    string s;
    cin >> s;
    ll n = s.size();
    if (s == string(n, '1')) {
        cout << n * n << '\n';
        return;
    }
    s += s;
    n = s.size();
    vector<ll> cnt(n);
    ll mx = 0;
    for (ll i=0; i<n; i++) {
        if (i != 0) cnt[i] += cnt[i-1];
        if (s[i] == '1') cnt[i]++;
        else cnt[i] = 0;
        mx = max(mx, cnt[i]);
    }
    ll ans = 0;
    ll w = mx;
    ll h = 1;
    while (w > 0) {
        ans = max(ans, w * h);
        w--;
        h++;
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