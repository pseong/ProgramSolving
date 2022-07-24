#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
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
    ll n;
    cin >> n;
    vector<ll> v(n);
    map<ll, ll> mp;
    ll mx = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        mx = max(mx, ++mp[v[i]]);
    }
    if (mx == n) {
        cout << 0 << '\n';
        return;
    }
    ll ans = n - mx;
    while (mx < n) {
        ans++;
        mx *= 2;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}