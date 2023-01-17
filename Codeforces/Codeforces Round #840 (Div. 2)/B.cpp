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
    int n, k;
    cin >> n >> k;
    vector<int> h(n), p(n);
    for (int i=0; i<n; i++) cin >> h[i];
    for (int i=0; i<n; i++) cin >> p[i];
    pqg<pi> q;
    for (int i=0; i<n; i++) {
        q.push({p[i], h[i]});
    }
    int now = 0;
    while (true) {
        now += k;
        while (q.size() && q.top().second <= now) q.pop();
        if (q.empty()) break;
        k -= q.top().first;
        if (k <= 0) {
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