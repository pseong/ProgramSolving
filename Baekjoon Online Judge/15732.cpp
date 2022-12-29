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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k, d;
    cin >> n >> k >> d;
    struct S {
        ll a, b, c;
    } s[10101];
    for (int i=0; i<k; i++) {
        cin >> s[i].a >> s[i].b >> s[i].c;
    }
    ll lo = 1;
    ll hi = 1e10;
    ll ans = 0;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        ll cal = 0;
        for (int i=0; i<k; i++) {
            if (m >= s[i].a) cal += (min(m, s[i].b) - s[i].a) / s[i].c + 1;
        }
        if (cal >= d) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << '\n';
}