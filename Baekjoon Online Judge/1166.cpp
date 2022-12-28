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

ll n, l, w, h;

bool f(double m) {
    ll cnt = (ll)(l / m) * (ll)(w / m) * (ll)(h / m);
    return cnt >= n;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> w >> h;
    double lo = 0;
    double hi = 1e9;
    double ans = 0;
    for (int i=0; i<1000000; i++) {
        double m = (lo + hi) / 2;
        if (f(m)) {
            ans = m;
            lo = m;
        }
        else hi = m;
    }
    cout << fixed << setprecision(9) << ans << '\n';
}