#include <bits/stdc++.h>
#define int long long
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

const ll mod = 1e9+7;

ll powll(ll x, ll y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    ll r = powll(x, y/2);
    if (y%2) return r*r%mod*x%mod;
    else return r*r%mod;
}

void solve() {
    int n;
    cin >> n;
    n = 1LL<<n;
    n--;
    ll ans = powll(4, n-1) * 6 % mod;
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}