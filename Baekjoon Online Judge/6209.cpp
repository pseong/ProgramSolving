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

ll d, n, m;
vector<ll> v;

bool cal(ll x) {
    ll prev = 0;
    ll cnt = 0;
    for (int i=0; i<n; i++) {
        if (v[i] - prev < x) cnt++;
        else prev = v[i];
    }
    if (cnt < m) return true;
    else if (cnt == m) return d - prev >= m;
    else return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> d >> n >> m;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ll lo = 1;
    ll hi = d;
    ll ans = 0;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        if (cal(m)) {
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    cout << ans << '\n';
}