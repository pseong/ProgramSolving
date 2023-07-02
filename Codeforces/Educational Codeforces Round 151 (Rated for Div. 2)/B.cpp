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

struct Point {
    int x, y;
};

void solve(int CASE) {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    ll ans = 0;
    if (a.x <= b.x && a.x <= c.x) {
        ans += min(b.x, c.x) - a.x;
    }
    else if (a.x >= b.x && a.x >= c.x) {
        ans += a.x - max(b.x, c.x);
    }

    if (a.y <= b.y && a.y <= c.y) {
        ans += min(b.y, c.y) - a.y;
    }    
    else if (a.y >= b.y && a.y >= c.y) {
        ans += a.y - max(b.y, c.y);
    }
    cout << ans + 1 << '\n';
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