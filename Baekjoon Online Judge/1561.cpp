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

ll n, m, v[10101];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> v[i];
    }

    ll lo = 0;
    ll hi = 6e10;
    ll ans = 0;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll cal = 0;
        vector<ll> left;
        for (int i=0; i<m; i++) {
            if (mid % v[i] == 0) left.push_back(i + 1);
            cal += (mid + v[i] - 1) / v[i];
        }
        if (cal <= n - 1) {
            ll p = n - cal;
            if (left.size() >= p) {
                cout << left[p-1] << '\n';
                return 0;
            }
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    assert(false);
}