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
    int n; cin >> n;
    int lo = 1;
    int hi = n;
    int ans = 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << lo << ' ' << mid << endl;
        int sz = mid - lo + 1;
        int cnt = 0;
        for (int i=0; i<sz; i++) {
            int a; cin >> a;
            if (a < lo || a > mid) cnt++;
        }
        if (sz%2 == 0 && cnt%2 == 1 || sz%2 == 1 && cnt%2 == 0) {
            hi = mid;
            ans = mid;
        }
        else {
            lo = mid+1;
            ans = mid+1;
        }
    }
    cout << "! " << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}