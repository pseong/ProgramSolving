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
    int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    int one = 0;
    int go = x1;
    while (go) {
        go /= 10;
        one++;
    }
    int two = 0;
    go = x2;
    while (go) {
        go /= 10;
        two++;
    }
    if (one+p1 > two+p2) {
        cout << ">\n";
        return;
    }
    else if (one+p1 < two+p2) {
        cout << "<\n";
        return;
    }

    int d = abs(one - two);
    if (one > two) {
        for (int i=0; i<d; i++) {
            x2 *= 10;
        }
    }
    else if (one < two) {
        for (int i=0; i<d; i++) {
            x1 *= 10;
        }
    }
    if (x1 > x2) {
        cout << ">\n";
    }
    else if (x1 < x2) {
        cout << "<\n";
    }
    else {
        cout << "=\n";
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