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

ll _cal(ll x) {
    if (x == 0) return 0;
    int cnt = 0;
    ll go = x;
    ll f = 1;
    while (go) {
        cnt++;
        f = go % 10;
        go /= 10;
    }
    ll res = 0;
    for (int i=0; i<cnt-1; i++) {
        res += 45 * (x / 10);
    }
    ll mul = x / f;
    for (int i=1; i<f; i++) {
        res += (ll)i * mul;
    }
    res += f;
    return res;
}

ll cal(ll x) {
    int cnt = 0;
    vector<ll> v;
    ll go = x;
    ll f = 1;
    while (go) {
        cnt++;
        f = go % 10;
        v.push_back(go % 10);
        go /= 10;
    }
    ll now = 0;
    ll res = 0;
    reverse(v.begin(), v.end());
    ll z = 1;
    for (int j=0; j<cnt-1; j++) {
        z *= 10;
    }
    for (int i=0; i<cnt; i++) {
        res += _cal(v[i] * z);
        z /= 10;
    }
    string s = to_string(x);
    for (int i=0; i<(int)s.size()-1; i++) {
        ll a = s[i] - '0';
        ll b = stoll(s.substr(i + 1));
        res += a * b;
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