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

int n, r, g, b, ans = 1e9;
struct S {
    int r, g, b;
} s[50];

void go(int idx, int nowR, int nowG, int nowB, int cnt) {
    if (idx == n) {
        if (cnt > 1) {
            int now = abs(r - nowR/cnt) + abs(g - nowG/cnt) + abs(b - nowB/cnt);
            ans = min(ans, now);
        }
        return;
    }
    go(idx + 1, nowR, nowG, nowB, cnt);
    if (cnt < 7) go(idx + 1, nowR + s[idx].r, nowG + s[idx].g, nowB + s[idx].b, cnt + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i].r >> s[i].g >> s[i].b;
    }
    cin >> r >> g >> b;
    go(0, 0, 0, 0, 0);
    cout << ans << '\n';
}