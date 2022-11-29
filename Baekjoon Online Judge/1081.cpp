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

vector<ll> p(11, 1);
ll cnt(ll n, ll i, ll j) {
   if (p[1] & 1) for (int k = 1; k <= 10; k++) p[k] = p[k - 1] * 10;
   ll ret = n / p[i + 1] * p[i];
   ll t = n / p[i] % 10;
   if (!j && !ret) return 0; // if leading zero
   if (t > j) ret += p[i];
   else if (t == j) ret += n % p[i] + 1;
   if (j == 0) ret -= p[i];
   return ret;
}

ll cal(ll x) {
    ll res = 0;
    for (int i=1; i<10; i++) {
        for (int j=0; j<10; j++) {
            res += cnt(x, j, i) * i;
        }
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll l, r;
    cin >> l >> r;
    if (l == 0) l++;
    cout << cal(r) - cal(l - 1) << '\n';
}