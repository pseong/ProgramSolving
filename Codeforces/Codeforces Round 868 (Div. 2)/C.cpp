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
    map<ll, ll> mp;
    for (int i=0; i<n; i++) {
        ll x;
        cin >> x;
        for (ll i=2; i*i<=x; i++) {
            while (x%i == 0) {
                mp[i]++;
                x /= i;
            }
        }
        if (x != 1) mp[x]++;
    }
    ll ans = 0;
    ll left = 0;
    for (auto& [x, y] : mp) {
        ans += y/2;
        if (y%2) left++;
    }
    ans += left / 3;
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