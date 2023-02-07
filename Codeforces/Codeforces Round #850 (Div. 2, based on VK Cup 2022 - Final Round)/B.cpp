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
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> c(n), d(n);
    for (int i=0; i<n; i++) cin >> c[i];
    for (int i=0; i<n; i++) cin >> d[i];
    int mv = d[0] + h - (c[0] + w);
    for (int i=0; i<n; i++) c[i] += mv;
    int m = 0;
    for (int i=0; i<n; i++) {
        int cs = c[i] - w + m;
        int ce = c[i] + w + m;
        int ds = d[i] - h;
        int de = d[i] + h;
        m += max(0, de - ce);
    }
    for (int i=0; i<n; i++) {
        int cs = c[i] - w + m;
        int ce = c[i] + w + m;
        int ds = d[i] - h;
        int de = d[i] + h;
        if (ds < cs || de > ce) {
            no();
            return;
        }
    }
    yes(); 
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