#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int k, x;
    cin >> k >> x;
    if (x <= (k-1)*k/2) {
        int lo = 1;
        int hi = k-1;
        int ans = k-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cal = mid*(mid+1)/2;
            if (cal >= x) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    else {
        x -= (k-1)*k/2;
        int lo = 1;
        int hi = k;
        int ans = k;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int cal = mid*(2*k - mid + 1) / 2;
            if (cal >= x) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << ans + k - 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}