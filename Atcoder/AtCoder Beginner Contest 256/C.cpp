#include <bits/stdc++.h>
#define int long long
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
    int ans = 0;
    int h[3], w[3];
    cin >> h[0] >> h[1] >> h[2];
    cin >> w[0] >> w[1] >> w[2];
    for (int a=1; a<30; a++) {
        for (int b=1; b<30; b++) {
            for (int d=1; d<30; d++) {
                for (int e=1; e<30; e++) {
                    int c = h[0] - a - b;
                    int f = h[1] - d - e;
                    int g = w[0] - a - d;
                    int H = w[1] - b - e;
                    int i = h[2] - g - H;
                    if (i == w[2] - c - f) {
                        ans += (c > 0 && f > 0 && g > 0 && H > 0 && i > 0);
                    }
                }
            }
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}