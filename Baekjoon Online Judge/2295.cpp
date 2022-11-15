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
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> v1;
    vector<pi> v2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            v1.push_back(v[i] + v[j]);
            v2.push_back({v[i] - v[j], i});
        }
    }
    sort(v1.begin(), v1.end());
    int ans = 0;
    for (int i=0; i<(int)v2.size(); i++) {
        auto it = lower_bound(v1.begin(), v1.end(), v2[i].first);
        if (it != v1.end() && *it == v2[i].first) {
            ans = max(ans, v[v2[i].second]);
        }
    }
    cout << ans << '\n';
}