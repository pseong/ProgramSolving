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

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<pll> p(c+1);
    vector<ll> range(c+10);
    range[1] = n+1;
    for (int i=1; i<=c; i++) {
        cin >> p[i].first >> p[i].second;
        range[i+1] = range[i] + p[i].second - p[i].first + 1;
    }

    for (int i=0; i<q; i++) {
        ll x;
        cin >> x;
        while (x > n) {
            for (int i=1; i<=c; i++) {
                if (range[i] <= x && x < range[i+1]) {
                    x -= range[i];
                    x += p[i].first;
                    break;
                }
            }
        }
        cout << s[x-1] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}