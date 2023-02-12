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
    vector<int> a(n + 1), ida(n + 1), b(n + 1), idb(n + 1);
    for (int i=1; i<=n; i++) cin >> a[i], ida[a[i]] = i;
    for (int i=1; i<=n; i++) cin >> b[i], idb[b[i]] = i;
    ll ans = 0;
    ll cnt = 0;
    for (int i=1; i<=n+1; i++) {
        if (i == n+1 || a[i] == 1 || b[i] == 1) {
            ans += cnt * (cnt+1) / 2;
            cnt = 0;
        }
        else cnt++;
    }
    int l = min(ida[1], idb[1]);
    int r = max(ida[1], idb[1]);
    for (int i=2; i<=n; i++) {
        if ((ida[i] < l || ida[i] > r) && (idb[i] < l || idb[i] > r)) {
            ll L = 0;
            ll R = 0;
            if (ida[i] < l && idb[i] < l) {
                L = l - max(ida[i], idb[i]);
                R = n+1 - r;
            }
            else if (ida[i] > r && idb[i] > r) {
                L = l;
                R = min(ida[i], idb[i]) - r;
            }
            else if (ida[i] < l) {
                L = l - ida[i];
                R = idb[i] - r;
            }
            else {
                L = l - idb[i];
                R = ida[i] - r;
            }
            ans += L * R;
        }
        l = min({l, ida[i], idb[i]});
        r = max({r, ida[i], idb[i]});
    }
    cout << ans + 1 << '\n';
}