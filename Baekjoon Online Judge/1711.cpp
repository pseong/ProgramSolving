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

ll dist(pi a, pi b) {
    return (ll)(a.first - b.first) * (a.first - b.first) + (ll)(a.second - b.second) * (a.second - b.second);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int ans = 0;
    for (int k=0; k<n; k++) {
        map<pi, int> mp;
        for (int i=0; i<n; i++) {
            if (i == k) continue;
            int g = gcd(v[i].first - v[k].first, v[i].second - v[k].second);
            int x = (v[i].first - v[k].first) / g;
            int y = (v[i].second - v[k].second) / g;
            if (y < 0) x *= -1, y *= -1;
            if (x < 0) x *= -1, y *= -1;
            mp[{x, y}]++;
        }
        for (int i=0; i<n; i++) {
            if (i == k) continue;
            int g = gcd(v[i].first - v[k].first, v[i].second - v[k].second);
            int x = (v[i].first - v[k].first) / g;
            int y = (v[i].second - v[k].second) / g;
            if (y < 0) x *= -1, y *= -1;
            if (x < 0) x *= -1, y *= -1;
            int a = y;
            int b = -x;
            if (b < 0) a *= -1, b *= -1;
            if (a < 0) a *= -1, b *= -1;
            ans += mp[{a, b}];
            mp[{x, y}]--;
        }
    }
    cout << ans << '\n';
}