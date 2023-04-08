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

int q(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int r;
    cin >> r;
    return r;
}

void ans(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
}

void solve(int CASE) {
    int n, m;
    cin >> n >> m;
    int r = q(1, 1);
    if (r == 0) {
        ans(1, 1);
        return;
    }
    if (1+r <= n && 1+r <= m) {
        int w = q(1+r, 1+r);
        if (w == 0) {
            ans(1+r, 1+r);
            return;
        }
        int w2 = q(1+r, 1+r-w);
        if (w2 == 0) {
            ans(1+r, 1+r-w);
            return;
        }
        else {
            ans(1+r-w, 1+r);
            return;
        }
    }
    else if (1+r <= n) {
        int w = q(1+r, 1);
        ans(1+r, 1+w);
        return;
    }
    else {
        int w = q(1, 1+r);
        ans(1+w, 1+r);
        return;
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