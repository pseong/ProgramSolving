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
    vector<ll> v(n + 1), pref(n + 1);
    for (int i=1; i<=n; i++) cin >> v[i];
    for (int i=1; i<=n; i++) pref[i] = pref[i-1] + ((i%2 == 0) ? -v[i] : v[i]);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int i = lower_bound(v.begin()+1, v.end(), l) - v.begin();
        int j = lower_bound(v.begin()+1, v.end(), r) - v.begin();
        i--; j--;
        
        ll ans = pref[j] - pref[i];
        if (j%2 == 0) ans += r;
        if (i%2 == 0) ans -= l;

        cout << ans << '\n';
    }
}