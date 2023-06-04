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

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    ll lo = 1;
    ll hi = (ll)1e9 * n;
    ll ans = hi;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        vector<int> left(n), right(n);
        pq<int> q;
        ll sum = 0;
        for (int i=0; i<n; i++) {
            q.push(v[i]);
            sum += v[i];
            while (sum > mid) {
                sum -= q.top();
                q.pop();
            }
            left[i] = q.size();
        }
        pq<int> q2;
        sum = 0;
        for (int i=n-1; i>=0; i--) {
            q2.push(v[i]);
            sum += v[i];
            while (sum > mid) {
                sum -= q2.top();
                q2.pop();
            }
            right[i] = q2.size();
        }
        bool ok = false;
        for (int i=0; i<n; i++) {
            if (i == n-1 && left[i] >= k) ok = true;
            if (i != n-1 && left[i] + right[i+1] >= k) ok = true;
        }
        if (ok) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}