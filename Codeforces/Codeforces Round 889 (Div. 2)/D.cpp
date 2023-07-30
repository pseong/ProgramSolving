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

    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    bitset<200000> bit;
    bit.set(0, 1);
    for (int i=0; i<n; i++) {
        auto b = bit;
        b >>= i;
        b <<= (i + v[i]);
        bit |= b;
        b = bit;
    }
    ll sum = 0;
    ll ans = 0;
    for (int i=0; i<n*2; i++) {
        if (i < n) sum += v[i];
        if (bit.test(i)) ans = max(ans, sum - i);
    }
    cout << ans << '\n';
}