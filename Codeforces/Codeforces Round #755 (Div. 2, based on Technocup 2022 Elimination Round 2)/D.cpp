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
    cout << "? " << 1 << ' ' << n << endl;
    int all; cin >> all;
    int lo = 1;
    int hi = n;
    int i = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << mid << ' ' << n << endl;
        int r; cin >> r;
        if (r == all) {
            i = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << "? " << i+1 << ' ' << n << endl;
    int r; cin >> r;
    int j = i + 1 + all - r;
    int cnt = all - (j-i)*(j-i-1)/2;
    lo = 1;
    hi = n;
    int ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cal = mid*(mid-1)/2;
        if (cal >= cnt) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    int k = j + ans - 1;
    cout << "! " << i << ' ' << j << ' ' << k << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}