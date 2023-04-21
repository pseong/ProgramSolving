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
    ll n, k;
    cin >> n >> k;
    vector<ll> l(n), r(n), d(n);
    for (int i=0; i<n; i++) cin >> l[i];
    for (int i=0; i<n; i++) cin >> r[i];
    for (int i=0; i<n; i++) d[i] = r[i] - l[i] + 1;
    ll now = 0;
    ll ans = 1e18;
    ll j = -1;
    ll sum = 0;
    ll cnt = 0;
    ll erase = 0;
    while (true) {
        while (sum < k) {
            if (j == -1 || (now == d[j] && j < n - 1)) {
                j++;
                if (d[j] == 1) cnt++;
                if (sum + d[j] <= k) {
                    sum += d[j];
                    now = d[j];
                }
                else {
                    now = k - sum;
                    sum = k;
                }
            }
            else if (now < d[j]) {
                ll left = d[j] - now;
                if (sum + left <= k) {
                    sum += left;
                    now += left;
                }
                else {
                    now += k - sum;
                    sum = k;
                }
            }
            else break;
        }
        if (sum == k) {
            ans = min(ans, l[j]+now-1 + (j+1-erase)*2);
        }
        if (cnt == 0) break;
        else {
            erase++;
            cnt--;
            sum--;
        }
    }
    if (ans == 1e18) cout << -1 << '\n';
    else cout << ans << '\n';
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