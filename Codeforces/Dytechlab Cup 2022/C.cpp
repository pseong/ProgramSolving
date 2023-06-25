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
    int n, r1, c1, r2, c2, r3, c3, x, y;
    cin >> n >> r1 >> c1 >> r2 >> c2 >> r3 >> c3 >> x >> y;
    int r, c;
    if (r1 == r2 || r1 == r3) r = r1;
    else r = r2;
    if (c1 == c2 || c1 == c3) c = c1;
    else c = c2;

    if ((r == 1 || r == n) && (c == 1 || c == n)) {
        if (x == r || y == c) yes();
        else no();
    }
    else if (n <= 3 && (r == 1 || r == n)) {
        if (y == c && (r%2 == x%2)) yes();
        else no();
    }
    else if (n <= 3 && (c == 1 || c == n)) {
        if (x == r && (c%2 == y%2)) yes();
        else no();
    }
    else {
        if ((r%2 == x%2) || (c%2 == y%2)) yes();
        else no();
    }
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