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
    vector<int> v(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    bool ok = true;
    for (int i=2; i<=n; i++) {
        if (v[i] < v[i-1]) ok = false;
    }
    ll k;
    cin >> k;
    ll ans = 0;
    if (ok) {
        vector<ll> cnt(n + 1);
        for (int i=2; i<=n; i++) {
            cnt[i] = v[i] - v[i-1];
        }
        for (int i=2; i<=n; i++) {
            if (cnt[i] * (i - 1) <= k) {
                ans += cnt[i];
                k -= cnt[i] * (i - 1);
            }
            else {
                ans += k / (i - 1);
                cout << ans << '\n';
                return 0;
            }
        }
    }
    else {
        int mx = v[1];
        for (int i=2; i<=n; i++) mx = max(mx, v[i]);
        ll sum = 0;
        for (int i=1; i<=n; i++) sum += mx - v[i];
        if (k < sum) {
            cout << 0 << '\n';
            return 0;
        }
        else if (k >= sum) {
            k -= sum;
            ans++;
        }
    }
    ans += k / n;
    cout << ans << '\n';
}