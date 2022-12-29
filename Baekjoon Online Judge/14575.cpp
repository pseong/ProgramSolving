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

int n, t, l[1010], r[1010];

bool cal(int m) {
    int lo = 0;
    int hi = 0;
    for (int i=0; i<n; i++) {
        lo += l[i];
        hi += min(m, r[i]) - l[i];
    }
    return (lo <= t && t <= lo + hi);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> t;
    for (int i=0; i<n; i++) cin >> l[i] >> r[i];
    int lo = *max_element(l, l+n);
    int hi = 1e6;
    int ans = -1;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cal(m)) {
            ans = m;
            hi = m - 1;
        }
        else lo = m + 1;
    }
    cout << ans << '\n';
}