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
    int n;
    cin >> n;
    vector<int> k(n), h(n);
    for (int i=0; i<n; i++) {
        cin >> k[i];
    }
    for (int i=0; i<n; i++) {
        cin >> h[i];
    }
    vector<pi> events;
    for (int i=0; i<n; i++) {
        events.push_back({k[i]-h[i]+1, k[i]});
    }
    srt(events);
    vector<ll> v;
    int lo = 1;
    int hi = 0;
    for (pi p : events) {
        if (p.first > hi) {
            v.push_back(hi - lo + 1);
            lo = p.first;
            hi = p.second;
        }
        else {
            hi = max(hi, p.second);
        }
    }
    v.push_back(hi - lo + 1);
    ll ans = 0;
    for (ll x : v) {
        ans += x * (x+1) / 2;
    }
    cout << ans << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}