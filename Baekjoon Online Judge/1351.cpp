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

ll n, p, q;
map<ll, ll> mp;

ll a(ll x) {
    if (mp.find(x) != mp.end()) return mp[x];
    else return mp[x] = a(x/p) + a(x/q);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mp[0] = 1;
    cin >> n >> p >> q;
    cout << a(n);
}