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
    vector<pll> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    ll ans = 18e9;
    for (int k=1; k<(1<<n); k++) {
        ll a = 1, b = 0;
        for (int i=0; i<n; i++) {
            if (k & (1<<i)) {
                a *= v[i].first;
                b += v[i].second;
            }
        }
        ans = min(ans, abs(a-b));
    }
    cout << ans << '\n';
}