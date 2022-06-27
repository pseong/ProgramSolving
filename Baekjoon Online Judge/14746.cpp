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
    int n, m;
    cin >> n >> m;
    int c1, c2;
    cin >> c1 >> c2;
    vector<int> p(n), q(m);
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> p[i];
    }
    for (int i=0; i<m; i++) {
        cin >> q[i];
        mp[q[i]]++;
    }
    srt(p);
    srt(q);
    int mn = 200000000;
    for (int i=0; i<m; i++) {
        auto it = lower_bound(p.begin(), p.end(), q[i]);
        if (it != p.end()) {
            mn = min(mn, abs(q[i] - *it));
        }
        if (it != p.begin()) {
            it--;
            mn = min(mn, abs(q[i] - *it));
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        auto it = mp.find(p[i] + mn);
        if (it != mp.end()) {
            ans += it->second;
        }
        if (mn == 0) continue;
        it = mp.find(p[i] - mn);
        if (it != mp.end()) {
            ans += it->second;
        }
    }
    cout << mn+abs(c1-c2) << ' ' << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}