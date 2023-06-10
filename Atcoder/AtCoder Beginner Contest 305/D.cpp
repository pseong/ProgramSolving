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

bool b[1000000001];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a, b;
    cin >> a;
    int m = n/2;
    vector<pi> v(m + 1);
    for (int i=1; i<=m; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector<ll> pref(m + 1);
    for (int i=1; i<=m; i++) {
        pref[i] = pref[i-1] + v[i].second - v[i].first;
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int idx1 = lower_bound(v.begin()+1, v.end(), make_pair(a, -(int)2e9)) - v.begin();
        int idx2 = lower_bound(v.begin()+1, v.end(), make_pair(b, -(int)2e9)) - v.begin();
        if (idx2 == 1) {
            cout << 0 << '\n';
            continue;
        }
        idx2--;

        ll ans = 0;
        if (idx2 >= idx1-1) ans = pref[idx2] - pref[idx1-1];
        if (v[idx1-1].second >= a) ans += v[idx1-1].second - a;
        if (v[idx2].second >= b) {
            ans -= v[idx2].second - b;
        }

        cout << ans << '\n';
    }
}